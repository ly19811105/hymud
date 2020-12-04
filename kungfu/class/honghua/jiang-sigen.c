// Last Modified by winder on Sep. 12 2001
// jiang-sigen.c ���ĸ�

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("���ĸ�", ({ "jiang sigen", "jiang","sigen" }));
	set("title", HIR"�컨��"HIG"ʮ������"NOR);
	set("nickname", HIY"ͭͷ����"NOR);
	set("long", "ͭͷ���㽯�ĸ��ڻ�������ʮ���ѽ��Σ�������������\n");
	set("gender", "����");
	set("class", "fighter");
	set("age", 21);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 20);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 1100);
	set("max_jing", 800);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 150000);

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("cuff", 80);
	set_skill("parry", 80);
	set_skill("club", 80);
	set_skill("baihua-cuocuff", 120);
	set_skill("honghua-shengong", 80);
	set_skill("zui-gun", 150);
	set_skill("youlong-shenfa", 120);

	map_skill("dodge", "youlong-shenfa");
	map_skill("force", "honghua-shengong");
	map_skill("cuff", "baihua-cuocuff");
	map_skill("club", "zui-gun");
	map_skill("parry", "zui-gun");
	prepare_skill("cuff", "baihua-cuocuff");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({	
		(: perform_action, "cuff.cuo" :),			
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	create_family("�컨��", 2, "����");

 	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"obj/tiejiang")->wield();
}
