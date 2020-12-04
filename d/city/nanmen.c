// Room: /city/nanmen.c
// YZC 1995/12/04 

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "������");
	set("long", @LONG
һ���ߴ�ĳ��������ڶɽ���ͷ������Ƕ�С������š�����ʯ�
��ǽ�Ͻ���һ����¥������Ѳ�ߵĹٱ��Ǳ������Ļ���Ц������������
�����Ǻ�������ִ�ڡ����Ҹ���һ��ˮ�ţ����ڹٺӺ�С�ػ�����ͨ��
���������ˮ�˵ı�������ǽ�������˹���ƣ������˻������̸��и�
ҵ�Ĺ�棬���ſ����ż��Ű��ĸ�ʾ(gaoshi)��˲�̫��Ŀ����������
�˳������������ţ�������������Ⱥ����ʹ�˸��ܵ����ݵķ�����
LONG );
        set("outdoors", "city");
//	set("no_clean_up", 0);
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"south" : "/d/wudang/wdroad1",
		"north" : __DIR__"nanmendajie",
		"west"  : __DIR__"jiaowai8",
		"east"  : __DIR__"jiaowai7",
	]));
        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
		"/d/beijing/npc/shisong" :1,
        ]));
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n����֪��\n��ҩ��\n";
}
