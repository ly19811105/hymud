 // XXDER@FY3
inherit NPC;
#include <ansi.h>
void create()
{
    set_name("����" , ({ "qin xin","qin" }) );
    set("nickname",HIC"������"NOR);
    set("long", "һ������Ů��ϯ�ض�����ϥ�Ϸ���һ�Ž�β�٣����Ե��ࡣ������ľ��ͣ����\n��������һ��һ�𣬻������ͳ���\n");
        set("attitude", "friendly");
    set("age", 22);
    set("per",40);
        set("gender", "Ů��" );
        create_family("���Ƴ�",1, "��Ů");
    set("combat_exp", 2500000);
        set("chat_chance", 1);
        set("chat_msg", ({
        "�������ϥ�����٣����������ﻥ��Ӧ�𣬼��عأ���ת������\n",
        "������ü΢�����������ߺ��ͣ�������죬�����һ����һ�������ҡ���Ȼ���ˡ�\n",
        }) );
    set_skill("persuading", 550);
        set_skill("throwing", 200);
        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("finger", 200);
        set_skill("parry", 200);
        set_skill("strike", 200);
        set_skill("sword", 250);
        set_skill("blade", 200);
        set_skill("literate", 100);
        set_skill("mahayana", 500);
        set_skill("buddhism", 250);
        set_skill("jinding-zhang", 300);
        set_skill("tiangang-zhi", 300);
        set_skill("huifeng-jian", 300);
        set_skill("yanxing-dao", 300);
        set_skill("zhutian-bu", 300);
        set_skill("linji-zhuang", 250);
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("blade","yanxing-dao");
        map_skill("parry","huifeng-jian");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "strike.bashi" :),
                (: perform_action, "finger.lingkong" :),
                (: exert_function, "daxiao" :),
                (: exert_function, "fengyun" :),
                (: exert_function, "longhe" :),
                (: exert_function, "tiandi" :),                                
                (: exert_function, "zhixin" :), 
        }) );  
        setup();
    carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}      