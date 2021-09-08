#pragma once
#include "kimera_dsg_visualizer/visualizer_types.h"

#include <kimera_dsg/dynamic_scene_graph.h>

#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>

namespace kimera {

using ColorFunction = std::function<NodeColor(const SceneGraphNode&)>;

visualization_msgs::Marker makeBoundingBoxMarker(
    const LayerConfig& config,
    const SceneGraphNode& node,
    const VisualizerConfig& visualizer_config,
    const std::string& marker_namespace = "bounding_box");

visualization_msgs::Marker makeTextMarker(
    const LayerConfig& config,
    const SceneGraphNode& node,
    const VisualizerConfig& visualizer_config,
    const std::string& marker_namespace = "text_label");

visualization_msgs::Marker makeCentroidMarkers(
    const LayerConfig& config,
    const SceneGraphLayer& layer,
    const VisualizerConfig& visualizer_config,
    std::optional<NodeColor> layer_color = std::nullopt,
    const std::string& marker_namespace = "layer_centroids");

visualization_msgs::Marker makeCentroidMarkers(
    const LayerConfig& config,
    const SceneGraphLayer& layer,
    const VisualizerConfig& visualizer_config,
    const ColormapConfig& colors,
    const std::string& marker_namespace = "layer_centroids");

visualization_msgs::Marker makeCentroidMarkers(
    const LayerConfig& config,
    const SceneGraphLayer& layer,
    const VisualizerConfig& visualizer_config,
    const std::string& marker_namespace,
    const ColorFunction& color_func);

visualization_msgs::MarkerArray makeGraphEdgeMarkers(
    const SceneGraph& scene_graph,
    const std::map<LayerId, LayerConfig>& configs,
    const VisualizerConfig& visualizer_config);

visualization_msgs::Marker makeMeshEdgesMarker(
    const LayerConfig& config,
    const VisualizerConfig& visualizer_config,
    const DynamicSceneGraph& graph,
    const SceneGraphLayer& layer,
    const std::string& marker_namespace = "mesh_layer_edges");

visualization_msgs::Marker makeLayerEdgeMarkers(
    const LayerConfig& config,
    const SceneGraphLayer& layer,
    const VisualizerConfig& visualizer_config,
    const NodeColor& color);

visualization_msgs::Marker makeDynamicCentroids(
    const LayerConfig& config,
    const DynamicSceneGraphLayer& layer,
    const VisualizerConfig& visualizer_config,
    const NodeColor& color);

visualization_msgs::Marker makeDynamicEdges(const LayerConfig& config,
                                            const DynamicSceneGraphLayer& layer,
                                            const VisualizerConfig& visualizer_config,
                                            const NodeColor& color);

visualization_msgs::Marker makeDynamicLabel(const LayerConfig& config,
                                            const DynamicSceneGraphLayer& layer,
                                            const VisualizerConfig& visualizer_config);

}  // namespace kimera
