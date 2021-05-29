#pragma once

namespace VulkanGraphics {
    struct QueueFamilyIndices {
        std::optional<uint32_t> graphicsFamily;
        std::optional<uint32_t> presentFamily;
        bool isComplete() {
            return graphicsFamily.has_value() && presentFamily.has_value();
        }
    };

    struct SwapChainSupportDetails {
        VkSurfaceCapabilitiesKHR capabilities;
        std::vector<VkSurfaceFormatKHR> formats;
        std::vector<VkPresentModeKHR> presentModes;
    };
    
    class HelloTriangleApplication {
    public:
        static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
        void run();
        static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
            VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
            VkDebugUtilsMessageTypeFlagsEXT messageType,
            const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
            void* pUserData) {
            if (messageSeverity >= VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT) {
                // Message is important enough to show
                std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;
            }
            

            return VK_FALSE;
        }
    public:
        bool framebufferResized = false;


    private:
        void initWindow();
        void initVulkan();
        void mainLoop();
        void cleanup();

        
        void createInstance();
        bool checkValidationLayerSupport();
        std::vector<const char*> getRequiredExtensions();
        void setupDebugMessenger();
        void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
        void createSurface();
        void pickPhysicalDevice();
        void createLogicalDevice();
        bool isDeviceSuitable(VkPhysicalDevice device);
        bool checkDeviceExtensionSupport(VkPhysicalDevice device);
        QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
        SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
        void createSwapChain();
        void recreateSwapChain();
        void cleanupSwapChain();
        void createImageViews();
        void createRenderPass();
        void createGraphicsPipeline();
        VkShaderModule createShaderModule(const std::vector<char>& code);
        void createFramebuffers();
        void createCommandPool();
        void createCommandBuffers();
        void drawFrame();
        void createSemaphores();
        
        
        
    private:

        GLFWwindow* m_Window;
        uint32_t m_Height;
        uint32_t m_Width;

        VkInstance m_Instance;
        VkDebugUtilsMessengerEXT m_DebugMessenger;
        VkPhysicalDevice m_PhysicalDevice = VK_NULL_HANDLE;
        VkDevice m_Device;
        VkQueue m_GraphicsQueue;
        VkSurfaceKHR m_Surface;
        VkQueue m_PresentQueue;
        VkSwapchainKHR m_SwapChain;
        std::vector<VkImage> swapChainImages;
        VkRenderPass renderPass;
        VkPipelineLayout pipelineLayout;
        VkPipeline graphicsPipeline;
        std::vector<VkFramebuffer> swapChainFramebuffers;
        VkCommandPool commandPool;
        std::vector<VkCommandBuffer> commandBuffers;
        const int MAX_FRAMES_IN_FLIGHT = 2;
        size_t currentFrame = 0;
        std::vector<VkSemaphore> imageAvailableSemaphores;
        std::vector<VkSemaphore> renderFinishedSemaphores;
        std::vector<VkFence> inFlightFences;
        std::vector<VkFence> imagesInFlight;

        
        //
        
        VkFormat m_SwapChainImageFormat;
        VkExtent2D m_SwapChainExtent;
        //

        const std::vector<const char*> validationLayers = {
            "VK_LAYER_KHRONOS_validation"
        };
        const std::vector<const char*> deviceExtensions = {
            VK_KHR_SWAPCHAIN_EXTENSION_NAME
        };
        std::vector<VkImageView> swapChainImageViews;

#ifdef G_DEBUG
        const bool enableValidationLayers = true;
#else
        const bool enableValidationLayers = false;
#endif
        
    };
}

