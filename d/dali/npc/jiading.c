// jiading.c �Ҷ�

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void upgrade_title(object me,string arg);
string clear_title(string arg);
int ask_me();
void create()
{
	set_name("�Ҷ�", ({ "jia ding", "ding" }));
          set_name("�Ҷ�", ({ "jia ding", "ding","jia" }));
	set("title", "������������");
	set("long", "���Ǵ��������������ļҶ���\n");
	set("gender", "����");
	set("age", 40);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("max_qi", 300);
	set("max_jing", 200);
	set("neili", 200);
	set("max_neili", 200);
	set("jiali", 10);
	set("combat_exp", 10000);
	set("score", 2000);
	set("env/wimpy", 5);

        set_skill("force", 25);
        set_skill("dodge", 25);
        set_skill("parry", 25);
        set_skill("sword", 25);
        set_skill("cuff", 25);
	set_skill("kurong-changong", 25);
        set_skill("duanjia-sword", 25);
        set_skill("tiannan-step", 25);
        set_skill("jinyu-quan", 25);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("sword", "duanjia-sword");
	map_skill("cuff", "jinyu-quan");
	map_skill("parry", "jinyu-quan");
create_family("�����μ�",20,"�Ҷ�");
	set("inquiry", ([
		"ָ���书" : (: ask_me :),
	]));
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver",2 );
}

int ask_me()
{
	string oldtitle;
	object ob, me;
	me = this_object();
	ob = this_player();
	if ((int)ob->query_skill("kurong-changong",1) < 30)
	{
		command("say ���뵱�ҳ����������깦��ȥ��\n");
		return 1;
	}
if (!ob->query("title"))
return 1;
	oldtitle = ob->query("title");
	if ((strsrch(oldtitle, "�������������Ҷ�") >= 0) ||
	   (strsrch(oldtitle, "�������������Ů") >= 0)) 
	{
		ob->set_temp("fight_ok",1);
		command("say �ã���Ȼ������д裬�ǾͿ���ı�������ˡ�\n");
		return 1;
	}
	else
	{
		command("say ֻ�мҶ����Ů�������ҳ���\n");
		return 1;
	}
}

int accept_fight(object ob)
{
        object me  = this_object();
        if ( !ob->query_temp("fight_ok") ) return 0;

        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        ob->delete_temp("fight_ok");
        return 1;
}

int checking(object me, object ob)
{
	object obj;
	int my_max_qi, his_max_qi;

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if (me->is_fighting()) 
	{
		call_out("checking",2, me, ob);
		return 1;
	}

	if ( !present(ob, environment()) ) return 1; 

	if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
	{
		command("say ������ʤ����������Ǵ����μҵĺõ��� ! ��ϲ���� !\n");
		command("say ����Ѿ�����ʤ�δ����ҳ� !\n");
		upgrade_title(ob, "�������������ҳ�");
		return 1;
	}
	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
	{
		command("say ����" + RANK_D->query_respect(ob) + 
			"���ö����ϰ�������ڴ����μ��������г���ͷ�� !\n");
		return 1;
	}
	return 1;  
}
void upgrade_title(object ob,string arg)
{
	string title;
	title=arg+clear_title(ob->query("title"));
	ob->set("title",title);
}
string clear_title(string arg)
{
	if( (strsrch(arg, "�������������Ҷ�") >= 0) ||
	    (strsrch(arg, "�������������Ů") >= 0))
	{
		arg = replace_string(arg, "�������������Ů","");
		arg = replace_string(arg, "�������������Ҷ�","");
	}
	return arg;
}