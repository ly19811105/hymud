
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("������", ({"guang yunzi", "guang"}));
        set("gender", "����" );
        set("age", 43);
        set("long", "����ɽ���Ƕ��ڶ��������еĽܳ����\n");
        set("combat_exp", 250000);
	set("daoxing", 400000);

        set("attitude", "friendly");
        create_family("����ɽ���Ƕ�", 2, "��ͽ");
	set("int", 25);
	set("class", "taoist");

        set("eff_dx", 90000);
        set("nkgain", 300);

        set_skill("unarmed", 80);
     
        set("force", 450);
        set("max_force", 300);
        set("force_factor", 40);
        set("mana", 450);
        set("max_mana", 300);
	set("mana_factor", 20);
        setup();
	carry_object("/d/xiyou/lingtai/obj/daoguan")->wear();
        carry_object("/d/xiyou/lingtai/obj/cloth")->wear();
        carry_object("/d/xiyou/lingtai/obj/bang")->wield();
}
void attempt_apprentice(object ob)
{
	if ( ((int)ob->query("combat_exp")+(int)ob->query("daoxing") < 30000)) {
	command("say " + RANK_D->query_respect(ob) +
"�Ƿ�Ӧ�ڵ��м��书�������Ŭ�������շ�����");
	return;
	}
        command("say �ܺã�" + RANK_D->query_respect(ob) +
"���Ŭ�������ձض��гɡ�\n");
        command("recruit " + ob->query("id") );
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");
}

�