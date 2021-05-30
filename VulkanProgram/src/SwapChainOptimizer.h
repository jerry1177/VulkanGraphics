#pragma once
namespace VulkanGraphics {


	class SwapChainOptimizer
	{
	public:
		SwapChainOptimizer();
		~SwapChainOptimizer();
		
		static VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
		static VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
		static VkExtent2D chooseSwapExtent(GLFWwindow& window, const VkSurfaceCapabilitiesKHR& capabilities);
	private:

	};

	
}