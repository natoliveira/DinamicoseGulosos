#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// O problema de coloração é colorir vértices de forma que vértices adjacentes não tem a mesma cor
// A versão de decisão se trata de conseguir colorir ou não com k cores
//número de vértices
#define numOfVertices 4

// 0 - verde/green, 1 - blue/azul
char colors[][30] = {"Green", "Blue"};
int color_used = 2;
int colorCount;

//conexões dos gráficos
int graph[numOfVertices][numOfVertices] =  {{0, 1, 0, 1},
                                            {1, 0, 1, 0},
                                            {0, 1, 0, 1},
                                            {1, 0, 1, 0}};
                                            
//vértices
typedef struct{
    char name;
    bool colored;
    int color;
} Vertex;

//lista de vértices
Vertex *vertexArray[numOfVertices];

//verifica se tem vértice vizinho sem cor
int hasUncoloredNeighbours(int idx){
  for(int i=0;i<numOfVertices; i++){
    if(graph[idx][i] == 1 && vertexArray[i]->colored == false)
      return i;
  }
  return -1;
}

//é válido colorir com color?
 bool canColorWith(int colorIndex, int vertex) {
    Vertex *neighborVertex;
    for(int i=0; i<numOfVertices; i++){
      //pula se os vértices não estiverem conectados
      if(graph[vertex][i] == 0) continue;

      neighborVertex = vertexArray[i];
      if(neighborVertex->colored && neighborVertex->color == colorIndex)
          return  false;
    }

    return true;
}

//função que colore os grafos
bool setColors(int idx){
  int colorIndex, unColoredIdx;

    //Step: 1
    for (colorIndex=0; colorIndex<color_used; colorIndex++){
      // Step-1.1 : verifica a validade
      if(!canColorWith(colorIndex, idx)) continue; 

      //Step-1.2 : coloração
      vertexArray[idx]->color =  colorIndex;
      vertexArray[idx]->colored = true;
      colorCount++;

      //Step-1.3 : todos os vértices estão coloridos?
      if(colorCount == numOfVertices ) //Caso Base
          return true;

      //Step-1.4 : próximo vértice sem cor
      while((unColoredIdx = hasUncoloredNeighbours(idx)) != -1){
        if(setColors(unColoredIdx))
          return true;
      }

    }

    // Step-2 : Backtracking
    vertexArray[idx]->color = -1;
    vertexArray[idx]->colored = false;
    return false;
}


int main()
{
  //define o vértice
  Vertex vertexA, vertexB, vertexC, vertexD;
  vertexA.name = 'A';
  vertexB.name = 'B';
  vertexC.name = 'C';
  vertexD.name = 'D';

  //adiciona vértices ao array
  vertexArray[0] = &vertexA;
  vertexArray[1] = &vertexB;
  vertexArray[2] = &vertexC;
  vertexArray[3] = &vertexD;

  //define valores padroes para todos os vértices
  for(int i=0; i<numOfVertices;i++){
    vertexArray[i]->colored = false;
    vertexArray[i]->color = -1;
  }

//inicia a coloracao do primeiro vértice
  bool hasSolution = setColors(0);

//verifica se todos os vértices foram coloridos de maneira satisfatória
  if (!hasSolution)
      printf("No Solution");
  else {
      for(int i=0; i<numOfVertices;i++){
          printf("%c %s \n",vertexArray[i]->name,colors[vertexArray[i]->color]);
      }
  }

  return 0;
}