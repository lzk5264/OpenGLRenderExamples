OpenGL感觉算是学习图形渲染的一个入门图形API，相比于DirectX12以及Vulkan，OpenGL更抽象对用户更透明，不会过于复杂且能让学习者了图形管线渲染的流程，想要极致性能肯定还是要学DirectX12和Vulkan，所以作为图形渲染一年半的练习生，我选择学习OpenGL。

而提到OpenGL的学习资源，[LearnOpenGL](https://learnopengl.com/) 绝对算得上最顶级的那一批，该教程除了OpenGL本身，还有很多图形渲染的内容，是图形渲染入门的完美教程。然而，我在跟着该教程学习时，除了简单的shader、texture类之外，就没有类的划分，导致主函数文件代码极多不易管理与维护，如果一段时间不学习，在原有代码的基础上修改渲染场景，就很容易出错。长时间跟着该教程写代码而不变通，就容易学成一个不合格的软件工程师。

所以，我决定在跟着该教程学习的同时，用软件工程的知识对代码进行重构，使其符合一个基本的渲染器的架构，易于阅读学习与维护。

# Document

https://ordinary-stone-d20.notion.site/LearnOpenGL-1b9c368144fc803da5dafc225a009f3b?pvs=4