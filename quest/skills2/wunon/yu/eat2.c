// by tie@fengyun

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("С����", ({ "yu2" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��С����\n");
		set("unit", "��");
		set("no_drop","��Ҫ�Ҷ����ⶫ������ʹ��\n");
		set("no_get",1);
		set("no_give",1);
		set("no_steal",1);

		set("no_put",1);

		set("value", 450);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}