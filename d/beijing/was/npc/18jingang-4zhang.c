#include <ansi.h>
inherit NPC;
void create()
{
        set_name("��ɮ", ({ "zhang seng", "zhang", "seng"}) );
        set("long", "һ��ͺ�����У���¶�������������ʵ��\n"
                    "��������������µ�ʮ�˽��֮һ��\n");
        set("attitude", "heroism");
        set("title", "����������ʮ�˽��");
        set("nickname", WHT "���Ƚ��" NOR);
        set("age", 30);
        set("shen_type", -1);

        set("str", 15+random(20));
        set("int", 15+random(20));
        set("con", 15+random(20));
        set("dex", 15+random(20));
        
        set("max_qi", 20000);
        set("max_jing", 8000);
        set("neili", 20000);
        set("max_neili", 20000);
        set("jiali", 80);

        set("combat_exp", 300000+random(300000));
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "staff.zhen" :),
                (: exert_function, "powerup" :),
        }) );


        set_skill("force", 140+random(20));
        set_skill("longxiang", 140+random(20));
        set_skill("dodge", 140+random(20));
        set_skill("shenkong-xing", 140+random(20));
        set_skill("cuff", 140+random(20));
        set_skill("yujiamu-quan", 140+random(20));
        set_skill("staff", 140+random(20));
        set_skill("xiangmo-chu", 340+random(20));
        set_skill("parry", 140+random(20));
        set_skill("lamaism", 180);

        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("cuff", "yujiamu-quan");
        map_skill("parry", "xiangmo-chu");
        map_skill("staff", "xiangmo-chu");

        set_temp("apply/attack", 80+random(50));
        set_temp("apply/defense", 80+random(50));
        set_temp("apply/armor", 80+random(50));
        set_temp("apply/damage", 80+random(50));

        setup();

        carry_object(__DIR__"obj/jiasha")->wear();
        carry_object(__DIR__"obj/zhang")->wield();
}
void init()
{
        object ob;

        ::init();

        ob = this_player();

        command("yi");
        command("say ��˭��ô�󵨣���Ȼ������������Ƥ����Ұ��\n");
        remove_call_out("kill_ob");
        call_out("kill_ob", 1, ob); 
}

