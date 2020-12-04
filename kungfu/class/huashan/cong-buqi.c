// cong-buqi.c  �Բ���
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("�Բ���", ({ "cong buqi", "cong" }) );
        set("gender", "����");
        set("class", "swordsman");
        set("title", "��ɽ���ڵ�ʮ��������");
        set("age", 52);
        set("long",
                "�Բ����ǻ�ɽ���ڸ��֡�\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 14000);
        set("max_neili", 12400);
        set("jiali", 30);
        set("max_qi",12000);
        set("max_jing",11200);

        set("combat_exp", 5000000);
        set("shen", -200000);
        set("apprentice_available", 3);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
              (: perform_action, "sword.jm" :),
                (: perform_action, "sword.jianzhang" :),
                (: perform_action, "sword.jie" :),
                (: perform_action, "sword.xian" :),                
                (: perform_action, "dodge.huiyanfeiwu" :),   
                (: perform_action, "sword.feilong" :),
                (: exert_function, "powerup" :),
        }) );
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
        set_skill("unarmed", 80);
        set_skill("sword", 220);
        set_skill("force", 120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("literate", 100);
        set_skill("huashan-sword", 350);
        set_skill("huashan-neigong", 130);
        set_skill("huashan-ken", 80);
        set_skill("huashan-zhangfa", 80);
        set_skill("huashan-shenfa", 140);
        set_skill("zhengqijue",200);
        map_skill("sword", "huashan-sword");
        map_skill("parry", "huashan-sword");
        map_skill("force", "huashan-neigong");
        map_skill("unarmed", "huashan-zhangfa");
        map_skill("dodge", "huashan-shenfa");

        create_family("��ɽ�ɽ���", 13, "����");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        command("say �Ϸ�����ͽ��");
}