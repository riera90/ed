#include "gtest/gtest.h"
#include "MonticuloMediciones.hpp"
#include "funcionesAuxiliares.hpp"


TEST(Integration,load_from_file){
	ed::MonticuloMediciones heap;
	cargarMonticuloDeFichero("./output/Palma_del_Rio.txt.csv",heap);
	EXPECT_EQ("22-4-18",heap.top().getFecha().getFechaString());
	heap.remove();
	EXPECT_EQ("21-4-18",heap.top().getFecha().getFechaString());
	heap.remove();
	EXPECT_EQ("20-4-18",heap.top().getFecha().getFechaString());
	heap.remove();
	EXPECT_EQ("19-4-18",heap.top().getFecha().getFechaString());
	heap.remove();
	EXPECT_EQ("18-4-18",heap.top().getFecha().getFechaString());
	heap.remove();
	EXPECT_EQ("17-4-18",heap.top().getFecha().getFechaString());
	heap.remove();
	EXPECT_EQ("16-4-18",heap.top().getFecha().getFechaString());
	heap.remove();
	EXPECT_EQ("15-4-18",heap.top().getFecha().getFechaString());
	heap.remove();
	EXPECT_EQ("14-4-18",heap.top().getFecha().getFechaString());
	heap.remove();
	EXPECT_EQ("13-4-18",heap.top().getFecha().getFechaString());
}

// TEST(Integration,dulpicated_input){
// 	ed::MonticuloMediciones heap;
// 	cargarMonticuloDeFichero("./output/Palma_del_Rio.txt.csv",heap);
// 	cargarMonticuloDeFichero("./output/Palma_del_Rio.txt.csv",heap);
// 	EXPECT_EQ("22-4-18",heap.top().getFecha().getFechaString());
// 	heap.remove();
// 	EXPECT_EQ("21-4-18",heap.top().getFecha().getFechaString());
// 	heap.remove();
// 	EXPECT_EQ("20-4-18",heap.top().getFecha().getFechaString());
// 	heap.remove();
// 	EXPECT_EQ("19-4-18",heap.top().getFecha().getFechaString());
// 	heap.remove();
// 	EXPECT_EQ("18-4-18",heap.top().getFecha().getFechaString());
// 	heap.remove();
// 	EXPECT_EQ("17-4-18",heap.top().getFecha().getFechaString());
// 	heap.remove();
// 	EXPECT_EQ("16-4-18",heap.top().getFecha().getFechaString());
// 	heap.remove();
// 	EXPECT_EQ("15-4-18",heap.top().getFecha().getFechaString());
// 	heap.remove();
// 	EXPECT_EQ("14-4-18",heap.top().getFecha().getFechaString());
// 	heap.remove();
// 	EXPECT_EQ("13-4-18",heap.top().getFecha().getFechaString());
// }
