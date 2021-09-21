#include <fmt/core.h>

#include "openglwindow.hpp"

#include <imgui.h>

void OpenGLWindow::initializeGL() {
  auto windowSettings{getWindowSettings()};
  fmt::print("Initial window size: {}x{}\n", windowSettings.width,
             windowSettings.height);
}

void OpenGLWindow::paintGL() {
  // Set the clear color
  abcg::glClearColor(m_clearColor[0], m_clearColor[1], m_clearColor[2],
                     m_clearColor[3]);

  // Clear the color buffer
  abcg::glClear(GL_COLOR_BUFFER_BIT);
}



void OpenGLWindow::paintUI() {
  // Parent class will show fullscreen button and FPS meter
  // abcg::OpenGLWindow::paintUI();

  // Our own ImGui widgets go below
  {
    // Window begin
    ImGui::Begin("Jogo da Velha!");

    // Static text
    auto windowSettings{getWindowSettings()};
    ImGui::Text("Current window is an tic-tae-toe alpha version!");


    static char conteudoTeste[3][3];

    ImGui::Button("Reset", ImVec2(-1, 50));
    // See also IsItemHovered, IsItemActive, etc
    if (ImGui::IsItemClicked()) {
      
      for(int i=0; i<3; i++){

        conteudoTeste[i][0] = '\0';
        conteudoTeste[i][1] = '\0';
        conteudoTeste[i][2] = '\0';

      }

      fmt::print("Reset Button pressed.\n");
    }

    //ImGui::HelpMarker("Using TableNextRow() + calling TableNextColumn() _before_ each cell, manually.");
    if (ImGui::BeginTable("##table2", 3))
    {

      ImGui::TableNextRow();
      ImGui::TableNextColumn();

        for (int row = 0; row < 3; row++)
        {
        
          for(int col=0; col<3; col++){

            char charTeste = conteudoTeste[row][col];
            ImGui::Button(&(charTeste), ImVec2(-1, 50));
            // See also IsItemHovered, IsItemActive, etc
            if (ImGui::IsItemClicked() && conteudoTeste[row][col] == '\0'){
              conteudoTeste[row][col] = 'X';
              fmt::print("Button pressed.\n");
            }

            ImGui::TableNextColumn();
          }

        }
        
        ImGui::EndTable();
    }
    else{

      ImGui::Text("travou");

    }

    // Window end
    ImGui::End();
  }
}



