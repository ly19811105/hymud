// Npc: /kungfu/class/nanshaolin/fangshi.c
// Last Modified by winder on May. 29 2001

inherit F_MASTER;
inherit NPC;

void create()
{
	set_name("����", ({ "fang shi", "fang", "shi"}));
	set("long", "����һλ�����Ʋ����ĵ�����ɮ�ˡ���������δ�ѣ�����ȴ����\n"
		"���ýݣ������ƺ�ѧ��һ���书��\n");
	set("nickname", "��ͷ");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 100);
	set("combat_exp", 100000);
	set("score", 50);
	set_skill("hunyuan-yiqi", 60);
	set_skill("zhanzhuang-gong", 60);
	set_skill("shaolin-cuff", 60);
	set_skill("shaolin-leg", 60);
	set_skill("yiwei-dujiang", 60);
	set_skill("boluomi-hand", 60);
	set_skill("jingang-strike", 60);
	set_skill("wuxiang-finger", 60);
	set_skill("literate", 50);
	set_skill("buddhism", 50);
	set_skill("parry", 50);
	set_skill("force", 50);
	set_skill("yijinjing", 50);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("cuff", 50);
	set_skill("hunyuan-yiqi", 50);
	set_skill("luohan-quan", 50);
	set_skill("hand", 50);
	set_skill("fengyun-shou", 50);
	set_skill("qianye-shou", 50);
	set_skill("strike", 50);
	set_skill("sanhua-zhang", 50);
	set_skill("blade", 50);
	set_skill("cibei-dao", 50);

	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("hand", "qianye-shou");
	map_skill("strike", "sanhua-zhang");
	map_skill("blade", "cibei-dao");
	map_skill("parry", "damo-jian");
	prepare_skill("hand", "qianye-shou");
	prepare_skill("strike", "sanhua-zhang");

	create_family("��������", 21, "����");

	setup();
	carry_object("/d/shaolin/obj/xu-cloth")->wear();
	carry_object(__DIR__"jiedao")->wield();
}

#include "fang.h";