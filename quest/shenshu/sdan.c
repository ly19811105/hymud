#include <ansi.h>
inherit ITEM;
#include "/quest/givetaskgift.c"
string *w_object=({
"/clone/box/new/ar1",
"/clone/box/new/ar10",
"/clone/box/new/ar11",
"/clone/box/new/ar12",
"/clone/box/new/ar13",
"/clone/box/new/ar14",
"/clone/box/new/ar15",
"/clone/box/new/ar16",
"/clone/box/new/ar17",
"/clone/box/new/ar18",
"/clone/box/new/ar2",
"/clone/box/new/ar3",
"/clone/box/new/ar4",
"/clone/box/new/ar5",
"/clone/box/new/ar6",
"/clone/box/new/ar7",
"/clone/box/new/ar8",
"/clone/box/new/ar9",
"/clone/box/new/ar2",
"/clone/box/new/ar3",
"/clone/box/new/ar4",
"/clone/box/new/ar5",
"/clone/box/new/ar6",
"/clone/box/new/ar7",
"/clone/box/new/ar8",
"/clone/box/new/ar9",
"/clone/box/new/bt1",
"/clone/box/new/bt10",
"/clone/box/new/bt11",
"/clone/box/new/bt12",
"/clone/box/new/bt13",
"/clone/box/new/bt14",
"/clone/box/new/bt15",
"/clone/box/new/bt16",
"/clone/box/new/bt17",
"/clone/box/new/bt18",
"/clone/box/new/bt2",
"/clone/box/new/bt3",
"/clone/box/new/bt4",
"/clone/box/new/bt5",
"/clone/box/new/bt6",
"/clone/box/new/bt7",
"/clone/box/new/bt8",
"/clone/box/new/bt9",
"/clone/box/new/bt2",
"/clone/box/new/bt3",
"/clone/box/new/bt4",
"/clone/box/new/bt5",
"/clone/box/new/bt6",
"/clone/box/new/bt7",
"/clone/box/new/bt8",
"/clone/box/new/bt9",
"/clone/box/new/h1",
"/clone/box/new/h10",
"/clone/box/new/h11",
"/clone/box/new/h12",
"/clone/box/new/h13",
"/clone/box/new/h14",
"/clone/box/new/h15",
"/clone/box/new/h16",
"/clone/box/new/h2",
"/clone/box/new/h3",
"/clone/box/new/h4",
"/clone/box/new/h5",
"/clone/box/new/h6",
"/clone/box/new/h7",
"/clone/box/new/h8",
"/clone/box/new/h9",
"/clone/box/new/h2",
"/clone/box/new/h3",
"/clone/box/new/h4",
"/clone/box/new/h5",
"/clone/box/new/h6",
"/clone/box/new/h7",
"/clone/box/new/h8",
"/clone/box/new/h9",
"/clone/box/new/hd1",
"/clone/box/new/hd10",
"/clone/box/new/hd11",
"/clone/box/new/hd12",
"/clone/box/new/hd13",
"/clone/box/new/hd14",
"/clone/box/new/hd15",
"/clone/box/new/hd16",
"/clone/box/new/hd17",
"/clone/box/new/hd18",
"/clone/box/new/hd2",
"/clone/box/new/hd3",
"/clone/box/new/hd4",
"/clone/box/new/hd5",
"/clone/box/new/hd6",
"/clone/box/new/hd7",
"/clone/box/new/hd8",
"/clone/box/new/hd9",
"/clone/box/new/hd2",
"/clone/box/new/hd3",
"/clone/box/new/hd4",
"/clone/box/new/hd5",
"/clone/box/new/hd6",
"/clone/box/new/hd7",
"/clone/box/new/hd8",
"/clone/box/new/hd9",
"/clone/box/new/nk1",
"/clone/box/new/nk10",
"/clone/box/new/nk11",
"/clone/box/new/nk12",
"/clone/box/new/nk13",
"/clone/box/new/nk14",
"/clone/box/new/nk15",
"/clone/box/new/nk16",
"/clone/box/new/nk17",
"/clone/box/new/nk18",
"/clone/box/new/nk2",
"/clone/box/new/nk3",
"/clone/box/new/nk4",
"/clone/box/new/nk5",
"/clone/box/new/nk6",
"/clone/box/new/nk7",
"/clone/box/new/nk8",
"/clone/box/new/nk9",
"/clone/box/new/sc1",
"/clone/box/new/sc10",
"/clone/box/new/sc11",
"/clone/box/new/sc12",
"/clone/box/new/sc13",
"/clone/box/new/sc14",
"/clone/box/new/sc15",
"/clone/box/new/sc16",
"/clone/box/new/sc17",
"/clone/box/new/sc18",
"/clone/box/new/sc2",
"/clone/box/new/sc3",
"/clone/box/new/sc4",
"/clone/box/new/sc5",
"/clone/box/new/sc6",
"/clone/box/new/sc7",
"/clone/box/new/sc8",
"/clone/box/new/sc9",
"/clone/box/new/sd1",
"/clone/box/new/sd10",
"/clone/box/new/sd11",
"/clone/box/new/sd12",
"/clone/box/new/sd13",
"/clone/box/new/sd14",
"/clone/box/new/sd15",
"/clone/box/new/sd16",
"/clone/box/new/sd17",
"/clone/box/new/sd18",
"/clone/box/new/sd2",
"/clone/box/new/sd3",
"/clone/box/new/sd4",
"/clone/box/new/sd5",
"/clone/box/new/sd6",
"/clone/box/new/sd7",
"/clone/box/new/sd8",
"/clone/box/new/sd9",
"/clone/box/new/sd2",
"/clone/box/new/sd3",
"/clone/box/new/sd4",
"/clone/box/new/sd5",
"/clone/box/new/sd6",
"/clone/box/new/sd7",
"/clone/box/new/sd8",
"/clone/box/new/sd9",
"/clone/box/new/wi1",
"/clone/box/new/wi10",
"/clone/box/new/wi11",
"/clone/box/new/wi12",
"/clone/box/new/wi13",
"/clone/box/new/wi14",
"/clone/box/new/wi15",
"/clone/box/new/wi16",
"/clone/box/new/wi17",
"/clone/box/new/wi18",
"/clone/box/new/wi2",
"/clone/box/new/wi3",
"/clone/box/new/wi4",
"/clone/box/new/wi5",
"/clone/box/new/wi6",
"/clone/box/new/wi7",
"/clone/box/new/wi8",
"/clone/box/new/wi9",
"/clone/box/new/wi2",
"/clone/box/new/wi3",
"/clone/box/new/wi4",
"/clone/box/new/wi5",
"/clone/box/new/wi6",
"/clone/box/new/wi7",
"/clone/box/new/wi8",
"/clone/box/new/wi9",
"/clone/box/new/wt1",
"/clone/box/new/wt10",
"/clone/box/new/wt11",
"/clone/box/new/wt12",
"/clone/box/new/wt13",
"/clone/box/new/wt14",
"/clone/box/new/wt15",
"/clone/box/new/wt16",
"/clone/box/new/wt17",
"/clone/box/new/wt18",
"/clone/box/new/wt2",
"/clone/box/new/wt3",
"/clone/box/new/wt4",
"/clone/box/new/wt5",
"/clone/box/new/wt6",
"/clone/box/new/wt7",
"/clone/box/new/wt8",
"/clone/box/new/wt9",
"/clone/box/new/wt2",
"/clone/box/new/wt3",
"/clone/box/new/wt4",
"/clone/box/new/wt5",
"/clone/box/new/wt6",
"/clone/box/new/wt7",
"/clone/box/new/wt8",
"/clone/box/new/wt9",
});

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIY"��ת��"NOR, ({"jin dan", "jindan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ž�ת�𵤡�\n");
		set("value", 50000);
set("no_pawn",1);
	}
	setup();
}

int do_eat(string arg)
{
	int exp,pot,score;
object corpse,ob,who;
int mi,yi,yai,neili;
        object me = this_player();
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

        if ( (int)me->query_condition("medicine") > 0 || (int)me->query_condition("medicine1") >0)
	{
		me->add("max_neili", -1);
		message_vision(HIR "$N����һ�ž�ת�𵤣�ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
	}
	else
	{
	exp = 6888+random(3888);
	             pot = exp*0.8;
             score = random(300)+100;
             neili= random(50)+50;
             if ( me->query("hyvip"))
             {
             exp = exp*1.8;
	     pot = pot*1.8;
             score = score*2;
             neili= neili*2;
             }	
             

        message_vision(HIY "$N����һ�ž�ת�𵤣�ֻ������������ԴԴ��������������һ�����Ƶ�!\n" NOR, me);
           addnl(me,"exp",exp);
        addnl(me,"score",score);
        me->add("max_neili", 100);
   tell_object(me,"�������������һ�ٵ�!"NOR+"��\n"NOR);
   if (me->query("4zhuan")
    || me->query("5zhuan"))
{
if (random(8)==1 || me->query("hyvip"))
{

me->add("expmax",1);

tell_object(me,HIR"��ɳ�������óɹ�!\n"+NOR);
}
}

if (random(8)==0  || me->query("hyvip"))
{
me->add("mpgx",1);
tell_object(me,"������ɹ���������!"NOR+"��\n"NOR);
}

if (random(3)==0)
{
       int rand;
//object ob;
       rand=random(sizeof(w_object));
           ob=new(w_object[rand]);

 if(ob)
{
        ob->move(me);
message("channel:chat", HIM"������ҥ�ԡ���˵"+me->name() + "ͨ�����������ҵ���"+ob->query("name")+HIM"!"NOR"��\n", users());
environment(this_object())->set("alrd",1);
}
else            tell_object(me,"���ʲôҲû��!"NOR+"��\n"NOR);
}


if (random(2)==0)
{
        corpse=new("/clone/gem/gem");
if (corpse->query("level") >4
&& random(3)>0)
{
        corpse=new("/clone/gem/gem");
}


message("channel:chat", HIM"������ҥ�ԡ���˵"+me->name() + "ͨ�����������ҵ���һ��"+corpse->query("name")+HIM"!"NOR"��\n", users());
             corpse->move(me);
}
	}

mi=1;
if (random(4)==0) mi=2;
if (random(18)==0) mi=3;
if (random(32)==0) mi=4;
if (random(64)==0) mi=5;
if (random(128)==0) mi=6;	
if (random(256)==0) mi=7;
if (random(512)==0) mi=8;
if (random(1024)==0) mi=9;
if (random(2048)==0) mi=10;				

yi=1;
if (random(8)==0) yi=2;
if (random(64)==0) yi=3;
if (random(128)==0) yi=4;
if (random(256)==0) yi=5;
if (random(512)==0) yi=6;	

yai=7;
if (random(8)==0) yai=8;
if (random(64)==0) yai=9;
if (random(128)==0) yai=10;
if (random(256)==0) yai=11;
if (random(512)==0) yai=12;	
who=me;
if (random(8)==0)
{

           ob = new("/p/newweapon/weaponobj/kuangshi"+mi);
           ob->move(who);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
}

if (random(9)==0)
{

           ob = new("/p/newweapon/weaponobj/buliao"+mi);
           ob->move(who);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
}

if (random(28)==0)
{

           ob = new("/p/newweapon/weaponobj/material"+yi);
           ob->move(who);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
}

if (random(27)==0)
{

           ob = new("/p/newweapon/weaponobj/material"+yai);
           ob->move(who);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
}

        me->apply_condition("medicine", 100);
me->apply_condition("medicine1", 100);	
	destruct(this_object());
	return 1;
}