/*
 * CPersistentStorage.h
 *
 *  Created on: Dec 3, 2018
 *      Author: swapnil
 */

#ifndef CPERSISTENTSTORAGE_H_
#define CPERSISTENTSTORAGE_H_
#include <string>
#include "CWpDatabase.h"
#include "CPoiDatabase.h"
#include "CDatabase.h"
class CPersistentStorage
{
public:
	/**
	* The mode to be used when reading the data bases (see readData).
	*/
	enum MergeMode { MERGE, REPLACE };
	//virtual ~CPersistentStorage();
	/**
	* Set the name of the media to be used for persistent storage.
	* The exact interpretation of the name depends on the implementation
	* of the component.
	*
	* @param name the media to be used
	*/
	virtual void setMediaName(std::string name) = 0;
	/**
	* Write the data to the persistent storage.
	*
	* @param waypointDb the data base with way points
	* @param poiDb the database with points of interest
	* @return true if the data could be saved successfully
	*/
	virtual bool writeData (const APT::CDatabase<CWaypoint>& waypointDb,const APT::CDatabase<CPOI>& poiDb) = 0;
	/**
	* Fill the databases with the data from persistent storage. If
	* merge mode is MERGE, the content in the persistent storage
	* will be merged with any content already existing in the data
	* bases. If merge mode is REPLACE, already existing content
	* will be removed before inserting the content from the persistent
	* storage.
	*
	* @param waypointDb the the data base with way points
	* @param poiDb the database with points of interest
	* @param mode the merge mode
	* @return true if the data could be read successfully
	*/

	virtual bool readData (APT::CDatabase<CWaypoint>& waypointDb, APT::CDatabase<CPOI>& poiDb,MergeMode mode) = 0;
	inline virtual ~CPersistentStorage(){}
};

#endif /* CPERSISTENTSTORAGE_H_ */
