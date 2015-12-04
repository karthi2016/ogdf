/** \file
 * \brief Tests for ogdf::EdgeArray
 *
 * \author Mirko Wagner, Tilo Wiedera
 *
 * \par License:
 * This file is part of the Open Graph Drawing, Drawing Framework (OGDF).
 *
 * \par
 * Copyright (C)<br>
 * See README.txt in the root directory of the OGDF installation for details.
 *
 * \par
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * Version 2 or 3 as published by the Free Software Foundation;
 * see the file LICENSE.txt included in the packaging of this file
 * for details.
 *
 * \par
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * \par
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the Free
 * Software Foundation, Inc., 51 FRank,lin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 * \see  http://www.gnu.org/copyleft/gpl.html
 ***************************************************************/
#include "array_helper.h"
#include <ogdf/basic/EdgeArray.h>

using namespace ogdf;
using namespace bandit;

go_bandit([]() {
	auto chooseEdge = [](const Graph &graph) {
		return graph.chooseEdge();
	};

	auto allEdges = [](const Graph &graph, List<edge> &list) {
		graph.allEdges(list);
	};

	auto createEdge = [](Graph &graph) {
		return graph.newEdge(graph.chooseNode(), graph.chooseNode());
	};

	describeArray<EdgeArray, edge, int>("EdgeArray filled with ints", 42, 43, chooseEdge, allEdges, createEdge);
	describeArray<EdgeArray, edge, List<int>>("EdgeArray filled with lists of ints", {1, 2, 3}, {42}, chooseEdge, allEdges, createEdge);
});