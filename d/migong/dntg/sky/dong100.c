#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"����֮���"NOR);
	set("long", @LONG
 ������磬Ʈ��������,����,�ذ����ɷ����Ļƽ����̳ɣ����ܵ�ǽ��
���컨���������������ıڻ��;��µ�ʯ�񡣿���������ˮ��ɢ��������
�Ĺ�â���޿�����Ʈ���ڿ��е�����ʹ��һ��������á�
LONG CYN);
	set("exits", ([
		"south" : __DIR__"dong99",
                	]));
set("no_npc",1);
          set("objects", ([
              "/d/migong/lev22/npc/bossz3" : 1,
              "/d/migong/lev22/npc/lev8" : 2,
              "/d/migong/lev22/npc/lev9" : 2,
              "/d/migong/lev15/npc/boss" : 2,
              "/clone/box/gboxm" : 3,
         ]));
	set("no_clean_up", 0);set("magicroom",1);set("outdoors","migong");set("magicset",1);
	setup();
	replace_program(ROOM);
}