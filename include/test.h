#ifndef TEST_REPL_H
#define TEST_REPL_H

#include <iostream>
#include <string>

class InputBuffer {
public:
    InputBuffer()
    : m_buffer{}, m_input_len{0} {}

public:
    std::string m_buffer;
    std::size_t m_input_len;
};

class BufferOperation {
public:
    BufferOperation()
    : m_new_buffer{nullptr} {}

    void CreateInputBuffer() {
        InputBuffer* new_buffer = new InputBuffer;

        if (new_buffer) {
            new_buffer->m_buffer = {};
            new_buffer->m_input_len = 0;
        }

        m_new_buffer = new_buffer;
    }

    void ShowPrompt() {
        printf("testdb > ");
    }

    void ReadInput() {
        if (m_new_buffer) {
            char delim = '\n';
            std::getline(std::cin, m_new_buffer->m_buffer, delim);
            m_new_buffer->m_input_len = m_new_buffer->m_buffer.size();
        }
    }

    int ProcessInput() {
        if (m_new_buffer) {
            if (m_new_buffer->m_input_len <= 0) {
                printf("Error !!\n");
                return -1;
            }

            if (m_new_buffer->m_buffer == ".exit") {
                CloseBuffer();
                return 1;
            } else {
                printf("Invalid command %s.\n", m_new_buffer->m_buffer.c_str());
                return 0;
            }
        }

        return -1;
    }

    void CloseBuffer() {
        if (m_new_buffer) {
            delete m_new_buffer;
            m_new_buffer = nullptr;
        }
    }

    ~BufferOperation() {
        std::cout << "Destructor called\n";
        if (m_new_buffer) {
            delete m_new_buffer;
            m_new_buffer = nullptr;
        }
    }

private:
    InputBuffer* m_new_buffer;
};

#endif // !TEST_REPL_H
