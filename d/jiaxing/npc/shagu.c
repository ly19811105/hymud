// shagu.c

inherit NPC;

void create()
{
	set_name("ɵ��", ({"sha gu","shagu"}) );
        set("gender", "Ů��" );
        set("age", 21);
        set("long", "����һ��ɵ������С���\n");

        set("combat_exp", 1500000);
	set("shen", 0);
	set("shen_type", 0);
        set("str", 132);
        set("dex", 118);
        set("con", 118);
        set("int", 10);
	set("max_qi", 1900);
	set("max_jing", 1720);
	set("neili", 11000);
	set("max_neili", 11000);
	set("jiali", 120);

	set_skill("force", 160);
	set_skill("bibo-shengong", 160);
	set_skill("dodge", 160);
	set_skill("anying-fuxiang", 165);
	set_skill("parry", 160);
	set_skill("strike", 180);
	set_skill("luoying-zhang", 180);
	set_skill("qimen-wuxing", 130);

	map_skill("force", "bibo-shengong");
	map_skill("dodge", "anying-fuxiang");
	map_skill("strike", "luoying-zhang");
	map_skill("parry", "luoying-zhang");
	prepare_skill("strike", "luoying-zhang");

	set("rank_info/respect", "С����");
	set("inquiry", ([
		"name": "���Ƕ�������ɵ�á�",
		"rumors": "���ֵܴ��˹ù�һ�ƣ����ֵܾ����ˡ�",
		"here": "������ţ�Ҵ塣",
		"�ù�": "�Ǹ�ɵС�ӽ������ض���",
		"ʦ��": "ʦ�����Ҵ�ȭ�档",
	]) );
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
	"ɵ�ó�����ҡҡҡ��ҡ�������ţ����Ž��Һñ���....\n",
	"ɵ����߶˵��ʦ��˵���������ƣ������棬���˴��Ҿʹ�����\n",
	"ɵ�ú�Ȼָ����ı��ӹ�����Ц�������Ī�����\n",
	"ɵ�ú���������ֵܣ������Һ����㣬��ɱ������ҡ�\n",
	"ɵ�ÿ���ǽ�ǣ������������������\n",
        }) );
        carry_object("/clone/misc/cloth")->wear();
}

int accept_object(object who, object ob)
{
	object money;

	if (ob->id("zhangfa tujie")) 
	{
		if (who->query_temp("shagu_silver")) {
			tell_object(who, "ɵ�ýӹ�ͼ�⣬���ſ��˰��죬�������ԣ���ŭ֮�£���ͼ��˺��ϡ�ã�\n");
			destruct(ob);
			return notify_fail("");
		}
		else {
			if (query_temp("silver_give")) {
				tell_object(who, "ɵ�ýӹ�ͼ�⣬���ſ��˰��죬�������ԣ�ֻ���ֻ��˸��㡣\n");
				return notify_fail("");
			}
			else {
				tell_object(who, "ɵ�ýӹ�ͼ�⣬���ſ��˰��죬�������ԣ�ֻ���ֻ��˸��㡣\n");
				tell_object(who, "ɵ��˵��������������������������أ��㿴����\n");
				tell_object(who, "ɵ�ø���һЩ���ӡ�\n");
				money = new("/clone/money/silver.c");
				money->set_amount(15);
				money->move(who);
				who->set_temp("shagu_silver", 1);
				set_temp("silver_give", 1);
				return notify_fail("");
			}
		}
	}
	return 0;
}
