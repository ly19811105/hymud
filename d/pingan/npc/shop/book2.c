// force_book.c

inherit ITEM;

void create()
{
	set_name("�����м�", ({ "parrybook" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"�Ȿ�����ֽ�Ŷ��Ѿ������ˣ�����ֻ��һЩ�ּ�ģ�����־䣬�ƺ�\n"
			"�ᵽһЩ�мܷ���ʲ��ġ�\n");
		set("value", 3000);
		set("material", "paper");
		set("skill", ([
			"name": 		"parry",		// name of the skill
			"exp_required":	0,				// minimum combat experience required
											// to learn this skill.
			"jing_cost":		30,				// gin cost every time study this
			"difficulty":	20,				// the base int to learn this skill
											// modify is gin_cost's (difficulty - int)*5%
			"max_skill":	50				// the maximum level you can learn
											// from this object.
		]) );
	}
}