// lady2.c

inherit NPC;

void create()
{
	set_name("����Ů��",({ "girl" }) );
	set("gender", "Ů��" );
	set("age", 16);
	set("long", 
"���Ǹ�ʮ��������Ľ���Ů����������ˣ�һ����������顣\n");
	set_temp("apply/defense", 5);
	set("combat_exp", 200);
//	set("shen", 100);
	set("shen_type", 1);
	set("str", 14);
	set("per", 28);
	set("dex", 15);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/cloth/female1-cloth")->wear();
}
