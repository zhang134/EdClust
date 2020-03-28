// =============================================================================
//
// =============================================================================

#include "common.h"

Options options;
SequenceDB seq_db;


////////////////////////////////////  MAIN /////////////////////////////////////
int main(int argc, char *argv[])
{
	string db_in;
	string db_out;
	clock_t start,finish;
	start=clock();
	double totaltime;
	//float begin_time = current_time();
	//float end_time;

	// ***********************************    parse command line and open file
	if (argc < 5) print_usage(argv[0]);
	if (options.SetOptions( argc, argv ) == 0) print_usage(argv[0]);
	options.Validate();

	db_in = options.input;   //options的类成员
	db_out = options.output; //options的类成员

	InitNAA( MAX_UAA );
	options.NAAN = NAAN_array[options.NAA];
	seq_db.NAAN = NAAN_array[options.NAA];

	//printf( "%i  %i  %i\n", sizeof(NVector<IndexCount>), seq_db.NAAN, sizeof(NVector<IndexCount>) * seq_db.NAAN );

	seq_db.Read( db_in.c_str(), options );
	cout << "total seq: " << seq_db.sequences.size() << endl;
	seq_db.SortDivide( options );

	seq_db.DoClustering( options );

	printf( "writing new database\n" );
	seq_db.WriteClusters( db_in.c_str(), db_out.c_str(), options );

	// write a backup clstr file in case next step crashes
	seq_db.WriteExtra1D( options );
	cout << "program completed !" << endl << endl;
	//end_time = current_time();
	//printf( "Total CPU time %.2f\n", end_time - begin_time );
	return 0;
} // END int main
