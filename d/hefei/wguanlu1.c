
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
��������Ȼ���������������������һ�ٰ�ʮ������İ����ռ����
�У�®�����ʶ��������ͺϷ�����һ�о��ء����滷ɽ�����ⷫӰ����ɫ��
�ġ���������Ҷ�����ڡ���ţɽ��������һʫ��д�������綨��ˮƽ������
��ˮ����� ����ߣ��÷��ͷ�����Զ�����������������û����ĺ����
媡��� ���볲���ĺ��⹵���ݺύ������ԴԶ��Ӣ������ɽ��ˮ�������
һ�ٶ�ʮ��Ķ��ˮ����Դ�ḻ�����Բ����㡢Ϻ�ס��з���ơ� 
LONG);

  set("exits", ([ 

  "northeast":__DIR__"ximen",
  "southwest":__DIR__"wguanlu2",
       ]));
 
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}
