 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
�ߴ��ʯ���Ʒ����ƺ��ſ��ޱۻ�ӭ��������������Դ�б�����
һ���������������У��ĺ���ɽΪ��һ���Ĵ�Ԫ�⣬ʮ����������Ԫ��
����֮�ƾÿɼ�һ�ߣ����������ӿ������������ŵ���ӡɮ������
�����ֵĹ��¡�
LONG
        );
        set("exits", ([ 
  "southwest" : __DIR__"ent3",
]));
        set("objects", ([
                __DIR__"obj/east_shi" : 1,
                __DIR__"npc/monk3" : 1,
       ]) );
        set("outdoors", "shaolinfy");
        set("coor/x",-200);
        set("coor/y",160);
        set("coor/z",20);
        setup();
        replace_program(ROOM);
}     