
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Db;

use Phalcon\Db\Profiler\Item;

/**
 * Instances of Phalcon\Db can generate execution profiles
 * on SQL statements sent to the relational database. Profiled
 * information includes execution time in milliseconds.
 * This helps you to identify bottlenecks in your applications.
 *
 * ```php
 * use Phalcon\Db\Profiler;
 * use Phalcon\Events\Event;
 * use Phalcon\Events\Manager;
 *
 * $profiler = new Profiler();
 * $eventsManager = new Manager();
 *
 * $eventsManager->attach(
 *     "db",
 *     function (Event $event, $connection) use ($profiler) {
 *         if ($event->getType() === "beforeQuery") {
 *             $sql = $connection->getSQLStatement();
 *
 *             // Start a profile with the active connection
 *             $profiler->startProfile($sql);
 *         }
 *
 *         if ($event->getType() === "afterQuery") {
 *             // Stop the active profile
 *             $profiler->stopProfile();
 *         }
 *     }
 * );
 *
 * // Set the event manager on the connection
 * $connection->setEventsManager($eventsManager);
 *
 *
 * $sql = "SELECT buyer_name, quantity, product_name
 * FROM buyers LEFT JOIN products ON
 * buyers.pid=products.id";
 *
 * // Execute a SQL statement
 * $connection->query($sql);
 *
 * // Get the last profile in the profiler
 * $profile = $profiler->getLastProfile();
 *
 * echo "SQL Statement: ", $profile->getSQLStatement(), "\n";
 * echo "Start Time: ", $profile->getInitialTime(), "\n";
 * echo "Final Time: ", $profile->getFinalTime(), "\n";
 * echo "Total Elapsed Time: ", $profile->getTotalElapsedSeconds(), "\n";
 * ```
 */
class Profiler
{
    /**
     * Active Item
     *
     * @var Item
     */
    protected activeProfile;

    /**
     * All the Items in the active profile
     *
     * @var Item[]
     */
    protected allProfiles;

    /**
     * Total time spent by all profiles to complete in nanoseconds
     *
     * @var float
     */
    protected totalNanoseconds = 0;

    /**
     * Returns the last profile executed in the profiler
     */
    public function getLastProfile() -> <Item>
    {
        return this->activeProfile;
    }

    /**
     * Returns the total number of SQL statements processed
     */
    public function getNumberTotalStatements() -> int
    {
        return count(this->allProfiles);
    }

    /**
     * Returns the total time in nanoseconds spent by the profiles
     */
    public function getTotalElapsedNanoseconds() -> double
    {
        return this->totalNanoseconds;
    }

    /**
     * Returns the total time in milliseconds spent by the profiles
     */
    public function getTotalElapsedMilliseconds() -> double
    {
        return this->getTotalElapsedNanoseconds() / 1000000;
    }

    /**
     * Returns the total time in seconds spent by the profiles
     */
    public function getTotalElapsedSeconds() -> double
    {
        return this->getTotalElapsedMilliseconds() / 1000;
    }

    /**
     * Returns all the processed profiles
     */
    public function getProfiles() -> <Item[]>
    {
        return this->allProfiles;
    }

    /**
     * Resets the profiler, cleaning up all the profiles
     */
    public function reset() -> <Profiler>
    {
        let this->allProfiles = [];

        return this;
    }

    /**
     * Starts the profile of a SQL sentence
     */
    public function startProfile(
        string sqlStatement,
        array sqlVariables = [],
        array sqlBindTypes = []
    ) -> <Profiler> {
        var activeProfile;

        let activeProfile = new Item();

        activeProfile->setSqlStatement(sqlStatement);
        activeProfile->setSqlVariables(sqlVariables);
        activeProfile->setSqlBindTypes(sqlBindTypes);
        activeProfile->setInitialTime(hrtime(true));

        if method_exists(this, "beforeStartProfile") {
            this->{"beforeStartProfile"}(activeProfile);
        }

        let this->activeProfile = activeProfile;

        return this;
    }

    /**
     * Stops the active profile
     */
    public function stopProfile() -> <Profiler>
    {
        var activeProfile;

        let activeProfile = <Item> this->activeProfile;

        activeProfile->setFinalTime(hrtime(true));

        let this->totalNanoseconds = this->totalNanoseconds + activeProfile->getTotalElapsedNanoseconds(),
            this->allProfiles[]    = activeProfile;

        if method_exists(this, "afterEndProfile") {
            this->{"afterEndProfile"}(activeProfile);
        }

        return this;
    }
}
