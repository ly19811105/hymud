// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("�ؼ��", ({"jian jiao", "jiao", "dumpling"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ���ۻƴ�Ƥ���ؼ�ȡ�\n");
    set("unit", "��");
    set("value", 200);
    set("food_remaining", 5);
    set("food_supply", 35);
  }
}
