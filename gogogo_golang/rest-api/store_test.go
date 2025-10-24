package main

type MockStore struct{}

func (s *MockStore) CreateUser() error {
	return nil
}

func (m *MockStore) CreateTask(t *Task) (*Task, error) {
	return &Task{}, nil
}
