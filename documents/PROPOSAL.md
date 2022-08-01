## Final Project Proposal (johnmf4-ao11-jordancs-ghoey2)

#### 1. **Leading Question**
How well do sectors characterize the fluctuation of stock market prices?

We are hoping to solve the problem of how well defined the stock market sectors truly are. Our project will depict how well the sectors are at grouping various stocks based on their fluctuations over periods of time. A well-formulated product looks like a set of algorithms and traversals that explain and show the various similarities between stock fluctuation patterns and how they should truly be grouped. Our project will look like a graph of nodes that are the individual stocks and each stock/node will have a spearman rank coefficient between two stocks that are above a certain threshold. This coefficient will act like an edge, a higher coefficient will have a shorter edge while a lower coefficient will have a longer edge unless the coefficient falls below a certain threshold, where there will be no edge that exists.


#### 2. **Dataset Acquisition and Processing**

We plan on using a dataset that has stock prices over a period of time. We’ll use the AlphaVantage API to generate a time series of stock prices over a period of a few years (discretized by day, for example). This dataset will then be used to create a matrix of stocks against time intervals. This can be then used to generate a graph in the process as follows: taking two vectors, and looking at their inner product (or spearman rank coefficient), we can develop correlations between two stocks. If the coefficient is above a certain bound, we create an edge between those two stocks, which are nodes. To create a similar directed graph, we can modify the spearman coefficient into a search-forward version, which measures the impact of one-stock’s prices onto another. We expect to expand upon ideas presented in this paper: https://www.researchgate.net/publication/308264777_Analysis_of_Equity_Markets_A_Graph_Theory_Approach#pf4, and this article https://julian-west.github.io/blog/visualising-asset-price-correlations



#### 3. **Graph Algorithms**

The first traversal we’ll use is a breadth-first search across the connected components of the graph, and then iteratively removing duplicate elements based on distance from the root. This will develop a hierarchy of related nodes in the given component. (i.e. if A is related to B is related to C is related to D, ABCD). Interpreting this, this gives a given sector (connected component) as a list of stocks in order of their relation to some root parameter. This is O(V + E), where V is nodes (n) and E is edges (n^2 in the worst case, which is not probable).  
  
The covered algorithm we will choose to implement on our graph is the shortest path algorithm (Floyd’s version, because it is faster, and we don’t need to see the shortest path between all vertices, just a passed parameter). This output will have the meaning of bringing the shortest set of connections between two stocks. Said otherwise, this determines how many “degrees” one stock is from another in a given sector. We believe that because we are using the standard implementation of Floyd’s algorithm it should have an O(n^3).  
  
The uncovered algorithm we will choose to implement is the strongly connected component algorithm. The input would be the entire graph while the output would be the graph with strongly connected components grouped together. This can be thought of as further dividing the stocks into more firmly-rooted sectors, and tells you which groups of stocks move as a unit, rather than as a chain reaction. We believe our target runtime will be O(V + E), where V is nodes (n) and E is edges (n^2 in the worst case, which is not probable). 






#### 4. **Timeline**

Our goals for week one are mostly data acquisition. Week two we will first start processing the data and determining how our data will be formatted, during this week we will also try to establish the skeleton of functions and classes our project will use. Week three we will start working on the algorithms. We will start implementing the BFS  traversal as well as Strongly connected component algorithm Floyd’s algorithm. Week four we will finish out BFS algorithms and start Floyd’s algorithm. On week 5 we will finish our algorithms and have a brainstorming session to start discussing how the paper and presentation should be structured. Week 6 we will finish the presentation and the report. 