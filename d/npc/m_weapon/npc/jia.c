// m_jia.c

#include <ansi.h>

#include <armor.h>

inherit S_ROBE;


int duanlian(object weapon);
int do_hui(object weapon);


string query_autoload() { return 1 + ""; }	//autoload weapon

void init()
{
        add_action("do_duanlian","lianjia");
	add_action("do_hui","huijia");
	add_action("do_levelup","jijia");
}


void create()
{	
	object me;
	string w_name,w_id,w_or;
	int w_lv;
	me = this_player();
//��������
	w_name=me->query("jia/name");
	w_id = "my "+me->query("jia/id");
	w_or = me->query("jia/or");
	w_lv = me->query("jia/lv");
        if (!me->query("jia/name"))
        {
	w_name="���Ƶļ���";
        }	
        if (!me->query("jia/id"))
        {
	w_id="jia";
        }	
        if (!me->query("jia/or"))
        {
	w_or="ǧ����ľ";
        }	
        if (!me->query("jia/lv"))
        {
	w_lv=1;
        }	
        if (me->query("jia/lv",1) > 200)
        {
	w_lv=200;
        }	

        set("material", "fur");
	set_name(w_name, ({w_id}));
	set("unit", "��");   
	set("value",0);
                set("armor_prop/armor", w_lv * 10);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
set("material", "fur");
//	set("material", "cloth");
//	set_desc(w_lv,w_or,w_name);
	switch(w_or)
		{
		case "ǧ����ľ" :
			set_weight(500);
set("material", "fur");
			break;
		case "���׽�ĸ" :
			set_weight(1000);
set("material", "fur");
			break;
		case "��˿����" :
			set_weight(30);
set("material", "fur");
			break;
		default :
		} 
	set("unit", "��");   
	if( me->query("jia/wear_msg"))
		set("wear_msg", me->query("jia/wear_msg")+"\n");
	else
		set("wear_msg", "$N����"+w_name+"�����ϡ�\n");
	if( me->query("jia/unequip_msg"))
		set("unequip_msg", me->query("jia/unequip_msg")+"\n");
	else
		set("unequip_msg", "$N���ϵ�"+w_name+"����������գ�ۼ���Ȼ����Ӱ�١�\n");
                set("armor_prop/armor", w_lv * 10);
set("armor_type","cloth");
set("material", "fur");
	setup();
}	



int do_duanlian(object weapon)
{
	object me;
	int w_zhi, w_level;
	string w_or;

	me=this_player();
	weapon=this_object();

	if( !weapon )
		return notify_fail("��Ҫ����ʲô?\n");

	if(weapon->query("equipped") ) 
	return notify_fail("������������!\n");

	if( (int)me->query("max_neili") < 10 )
		return notify_fail("��������������޷�����������\n");

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("��������������޷�����������\n");

if (userp(me) && !me->query_skill_mapped("force"))
return notify_fail("��û���ڹ�����ʹ���а�!\n");

	if( me->query_skill("shenzhao-jing", 1) > 100          )
		return notify_fail("���վ����������޷�����������\n");

	if( me->query_skill("shenzhao-jing", 1) > 100
            && (int)me->query("max_neili") < 5000 )
		return notify_fail("��������������޷�����������\n");
		
	if( (int)me->query("qi") < 150 )
		return notify_fail("������������޷�����������\n");

	if( (int)me->query("eff_qi") < 30 )
		return notify_fail("�����ڵ�����̫�����޷�����������\n");

	if( (int)me->query("eff_jing") < 10 )
		return notify_fail("�����ڵľ����޷����У����ܶ���������\n");

	if( ((int)me->query("potential") - (int)me->query("learned_points"))< 2 )
		return notify_fail("���Ǳ�ܲ������޷�����������\n");

	message_vision(HIR "$N��ָ�׼���һ������˿˿�Ĵ��˽�ȥ��\n" NOR, me);

	me->add("max_neili",-10);
	me->set("neili", (int)me->query("max_neili"));
	me->add("qi",-150);
	me->add("eff_qi",-30);
	me->add("jing",-30);
	me->add("eff_jing",-30);
	me->add("learned_points", 2);

	w_zhi = (int)me->query("jia/value");
	w_zhi++;
	me->set("jia/value", w_zhi);
	w_or = (string)me->query("jia/or");
	w_level = (int)me->query("jia/lv");
	if( w_zhi >= ((w_level + 1) * (w_level + 1)))
	{
		w_level++;
		me->set("jia/lv", w_level);
		message_vision(CYN "��������һ����һ����������$N�ļ��У������ˣ�\n" NOR,me);
		message_vision(HIG "$N�ļ׵ĵȼ�����ˣ�\n" NOR, me);
		weapon=this_object();
		if(weapon->query("equipped") ) 
			weapon->unequip();
		reload_object( weapon );
		me->set("jia/value",0);
		return 1;
	}
	message_vision(RED "$N�ļ���������!\n" NOR, me);
	return 1;
}

int do_hui(string arg)
{	
	string w_name;
	object me,ob;
	me=this_player();
	w_name=me->query("jia/name");
 	if (!id(arg))
	return notify_fail("��Ҫ����ʲô��\n");

	message_vision(HIR "$N���һ����һ����ף�һ���������¡������¡һ������"
			+w_name+HIR"��Ϊ����!\n" NOR,me);
	me->set("jia/make",0);
	destruct( this_object() );
	me->delete("weapon");
	me->save();

	return 1;
}

int  do_levelup(string arg)
{
	object me, ob;
	object gold;
	int cost = 1;
	int i,j,base,current;
	string id,name ;	
	string file,newfile,filestring;
	me = this_player();
	id = me->query("id");
        if( !arg ) return notify_fail("��Ҫ����ʲ��������\n");
        gold = present("gold_money", this_player());
        if( !gold) return notify_fail("������û�н��ӡ�\n");
        if( !objectp(ob = present(arg, me)) )
        return notify_fail("������û������������\n");
        if(me->is_busy())
        return notify_fail("����һ��������û����ɡ�\n");
        if( ob->query("equipped") )
        return notify_fail("�㲻�ɼ�װ�����˵�������\n");
        if( !ob->query("ownmake") )
        return notify_fail("��ֻ�ɼ��Լ������������\n");
	if( (int)me->query("qi") < 150 )
		return notify_fail("������������޷�������ף�\n");

	if( (int)me->query("eff_qi") < 30 )
		return notify_fail("�����ڵ�����̫�����޷�������ף�\n");

	if( (int)me->query("eff_jing") < 10 )
		return notify_fail("�����ڵľ����޷����У����ܶ�����ף�\n");
	if( (int)me->query("score") < 100 )
		return notify_fail("�����ڵĽ����������������ܶ�����ף�\n");

        if( ob->query("wield_msg") )
        return notify_fail("����������ȥ����һ�ߡ�\n");
	if( ((int)me->query("potential") - (int)me->query("learned_points"))< 20 )
		return notify_fail("���Ǳ�ܲ������޷�������ף�\n");
	j = (int)me->query("jia/lv");

	if(j<6) cost = 15*j;
	else if(j<11) cost = 20*j;
	else if(j<16) cost = 30*j;
	else if(j>500) cost = 200*j;
	else cost = 60*j;
        if((int) gold->query_amount() < 100)
        return notify_fail("������û����100�����ӡ�\n");
        if((int) gold->query_amount() < cost)
        return notify_fail("������û����" + sprintf("%d",cost)+ "�����ӡ�\n");
        gold->add_amount(-cost);
        me->start_busy(2);
	me->add("bellicosity",cost);
	seteuid(ROOT_UID);
	me->add("qi",-150);
	me->add("eff_qi",-30);
	me->add("jing",-30);
	me->add("eff_jing",-30);
	me->add("score",-100);
	me->add("learned_points", 20);
	me->set("jia/lv", j+1);
	me->save();
	reload_object(ob);
	message_vision(HIY "��������һ����һ���������$N��"+ob->name()+HIY"�������ˣ�\n" NOR,me);
	message_vision(HIG "$N��"+ob->name()+HIG"�ĵȼ�����ˣ�\n" NOR, me);
        seteuid(getuid());
	return 1;
}