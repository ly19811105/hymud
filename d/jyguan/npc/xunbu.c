// bukuai.c ����
// Freeze(Rtm) ��д  Beta 1.1 Ŀǰ��������-���Ų���ɱ���˲��첻�����ϲ�ȡ�ж� :P
// ��ȨΪ ��Ƶ ���������� / δ�����ɲ��ø��ơ�ʹ�á��Ķ�
// 1998/9/19

#include <ansi.h>
inherit NPC;

void catched(object me,object dest);
void greeting(object ob);
int catch_pk(object me,object dest);
int waiting(object me, object dest);
int checking(object me, object dest);

void create()
{
	set_name("����", ({ "bu kuai", "bu", "kuai" }));
	set("gender", "����");
	set("age", random(10) + 30);
	set("str", 30);
	set("dex", 16);
	set("long", "�������Ӿ��ǳ����ϵ����֣������ںڡ�������...\n");
	set("combat_exp", 100000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("sword", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 400); 
	set("max_neili", 400);
	set("jiali", 10);
	
        set("chat_chance",10);
        set("chat_msg",({
     "�������һ����˵�����������ھ�˭Ҳ����ɱ��...˭Ҫ��ɱ���˸������鷳�����������ȥ���Σ���\n",
     BLU"�����������ţ�����ɱ���ҲŲ������أ�ȴ�������ܹ��ݣ�ֻ����ɱ�˵�����ȥ�Ҳż��ã���˾�����������...�ߺ�...\n"NOR,
        (: random_move :)
	}));

	setup();
	carry_object("/d/city/obj/gangjian")->wield();
	carry_object("/d/city/obj/tiejia")->wear();
}

void init()
{
	object ob;
	::init();

	if (interactive(ob = this_player()))
        {
		remove_call_out("greeting");
	        call_out("greeting", 0, ob);
	}        
}

void greeting(object ob)
{
        object me;
        me = this_object();

	if(!ob || environment(ob) != environment()) return;
	if ( ob->query_condition("killer") )
	{
                if ( ! is_fighting()) 
                {
			call_out("catch_pk",0,me,ob);
			return;	
		}
		else
		{
			message_vision(HIC "$N��$n˵������˵���С�쵰ɱ���ˣ�����æ����������ʰ�㣡"
                                +RANK_D->query_rude(ob)+"������������������죡\n" NOR, me, ob);
			return;
		}
        }
	else
	{
		command("say ����ģ�������ôû����ɱ�ˣ��ò��������ӻ�ʲô...��������...");	
//		init();
	}
	return;
}

int catch_pk(object me,object dest)
{
	if( objectp(dest) && present(dest, environment(me))
		 && !environment(me)->query("no_fight"))
	{
//		if (dest->query("qi") == 0 || dest->query("qi") <= 30 ) 
		if ( dest->query("qi") <= 40)
//		if ( dest->query("qi") == 0 )
		{
			catched(me,dest);
               	        return 1;
		}

		message_vision(HIY "$N��$n˵������˵��ɱ���ˣ��ԹԶ����һ�ȥ����������������"
			+RANK_D->query_rude(dest)+"��������\n" NOR, me, dest);
		me->set_leader(dest);
                me->fight_ob(dest);
                
		dest->fight_ob(me);
               
		call_out("checking", 0,  me, dest);
		
	}
	else  
		call_out("waiting", 1, me, dest);
	
	return 1;
}

int waiting(object me, object dest)
{
	if ( objectp(dest) )
	{
		if (dest->is_ghost())
		{
			dest->apply_condition("killer",0);
			return 1;
		}
		else if (me->is_fighting() && present(dest, environment(me)))
		{
			call_out("checking", 0, me);
			return 1;
		}
		     else if (!me->is_fighting() && present(dest, environment(me)))
		     {
		     	      call_out("checking",0,me);
			      return 1;
		     }			
	}		
	
	remove_call_out("waiting");
	call_out("waiting", 10, me);
    return 1;
}

int checking(object me, object dest)
{
	object ob;
        
	if (me->query("qi") == 0)
		return 1;

	if (me->is_fighting()) 
	{
		call_out("checking",0,me);		
	        return 1;
	}
	else  init();

	if (objectp(ob = present("corpse", environment(me)))
		 && ob->query("victim_name") ==	dest->query("name") )
	{
		dest->apply_condition("killer",0);
		me->set_leader(0);
        	return 1;
	}

//	if (dest->query("qi") == 0 || dest->query("qi") <= 30 ) 
	if ( dest->query("qi") <= 40 )
//	if ( dest->query("qi") == 0 )
	{
		command("say �����checking()�ڹ���");
		catched(me,dest);
		return 1;
	} 
	else if (dest->query("qi") > 0) init();

	call_out("waiting", 0, me, dest);
	return 1;
}

void catched(object me,object dest)
{	
	command("say "+(string)dest->query("id")+(string)dest->query("qi"));
	
//!	dest->apply_condition("gvmt_jail", 20);
	dest->unconcious(); //�����в���Ӱ��	
//	command("get "+(string)dest->query("id"));
	command("say �ǣ�����ô�����ӻ��Ҹ����ӽа壡���Ѿ�û���ˣ�����ɣ�" );
	message_vision(HIC"ֻ����������һ����$N�׳��������˷���ס��Ѻ����"+(string)dest->query("name")+"������ط����ȥ��\n"NOR,me);

        dest->move("/wizhome/rtmhome/gvmt/jianyu_do");
	me->move("/wizhome/rtmhome/gvmt/jianyu_do");
	

	dest->apply_condition("killer",0);
//	command("drop "+(string)dest->query("id"));
	me->set_leader(0);
		
	message_vision(HIC"$N���˿���ĭ����"+(string)dest->query("name")+"���ص����ڵ��ϣ��ݺݵ�����һ�ţ�����һ��������Ьӡ��ת�����������뿪��\n"NOR,me);

	switch ( random(6) )
	{
	case 0 :
		me->move("/d/city/guangchang");
		break;
	case 1 :
		me->move("/d/city/beidajie1");
		break;
	case 2 :
		me->move("/d/city/nandajie1");
		break;
	case 3 :
		me->move("/d/city/xidajie1");
		break;
	case 4 :
		me->move("/d/city/dongdajie1");
		break;
	case 5 :
		me->move("/d/city/wumiao");
		break;
	}
	message_vision("$N���˹�����\n",me);
           	
	return;
}


