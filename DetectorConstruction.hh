#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Material.hh"

#include "G4PVPlacement.hh"
#include "G4UserLimits.hh"
#include "G4VisAttributes.hh"

class G4VPhysicalVolume;

// Class deriving from the virtual G4VUserDetectorConstruction class
class DetectorConstruction : public G4VUserDetectorConstruction
{

public:
	DetectorConstruction();
	virtual ~DetectorConstruction();
public:
	virtual G4VPhysicalVolume* Construct();
	virtual void ConstructSDandField();


private:

	G4double           WorldSizeX;
	G4double           WorldSizeY;
	G4double           WorldSizeZ;

	G4VPhysicalVolume* physiCavern;
	G4LogicalVolume*   logicCavern;
	G4Box*             solidCavern;

	G4VPhysicalVolume* physiTube;
	G4LogicalVolume*   logicTube;
	G4Tubs*          solidTube;

	G4Material*        defaultMaterial;
	G4Material*        detectorMaterial;

	void DefineMaterials();
	G4VPhysicalVolume* ConstructDetector();
	G4int fNofLayers;
};


#endif


