import bayou.sim;

using namespace bayou;

int main()
{
	c_sim* sim = new c_sim;
	if (sim == nullptr)
	{
		return 1;
	}

	if (!sim->place_piece(1, 0, { 0, 0 }))
	{
		return 1;
	}

	if (!sim->try_move({ { 0, 0 }, { 0, 1 } }))
	{
		return 1;
	}

	return 0;
}
