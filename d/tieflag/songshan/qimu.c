 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ĸʯ");
        set("long", @LONG
���سǲ�Զ���㵽��ĸʯ���ഫ������ĸ�����������������
ˮ�������ң�̫��֮���ͨ��������Ϳɽ�������ͷ���һ��ɽʯ��
·�������������ܿ�ɽ�����Ӽ��������ܵĴ��������Ź��Ȼ�Ϊʯ
ͷ����ʵ�������ף��������ʯʹ�ޣ���Ȼʯ��������������ʯ��
�Ӵ˽�������ĸʯ����������ɽ�������澰������ǰ�б���������
�ˡ�
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"shaoshi",
  "southeast" : __DIR__"dengfeng",
]));
        set("objects", ([
                __DIR__"npc/yumo" : 1,
       ]) );
        set("outdoors", "songshanfy");
        set("coor/x",-210);
        set("coor/y",110);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     