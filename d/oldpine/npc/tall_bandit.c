 // tall_bandit.c
inherit NPC; 
void create()
{
        set_name("����", ({ "bandit" }) );
        set("gender", "����");
        set("age", 27);
        set("long",     "��һﳤ�ø߸����ݣ���ɫ�԰ף�һ���޾���ɵ����ӡ�\n");
        set("combat_exp", 900);
        set("score", 100);
        set("attitude", "friendly");
        set_skill("sword", 15);
        set_skill("parry", 15);
        set_skill("dodge", 10);
   set("combat_exp", 400000+random(900000));
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
        }) );

	set("max_qi", 3000);
	set("max_jing", 3000);
	set("neili", 3000);
	set("max_neili", 3000);
        set_skill("unarmed", 80+random(180));
        set_skill("blade", 80+random(180));
        set_skill("parry", 80+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-blade", 80+random(380));
        
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 20);
        
        setup();
        carry_object(__DIR__"obj/long_sword")->wield();
        carry_object("/clone/misc/cloth")->wear(); 
        add_money("coin", 6);
}       
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{   
        if( !ob || environment(ob) != environment() )
                return;
        if (ob->query("class") != "bandit")
        {
                message_vision("$N��������������������ֵ��ǣ�������ڣ���\n", this_object() );
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
        }
        else if(ob->query("class")=="bandit")
        {
                message_vision("$N������Ц�����ֵܽ����ֵ������ҽ��᣿\n", this_object() );
        }
        return;
}     