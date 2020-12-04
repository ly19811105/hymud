#include <ansi.h>

inherit VRM_SERVER;

#define ENTER_ROOM_X    0
#define ENTER_ROOM_Y    0
#define ENTER_ROOM_Z    0

void create()
{
	// �Թ��������̳е�����ĵ������ơ�
	set_inherit_room( ROOM ); set("no_clean_up",1);

	// �Թ�����Ҫ����͵ȼ���

        set_lonely_create(1);


	//�Թ�������Ĺ��
        set_maze_npcs(__DIR__"npc/0005/man4");

	// �Թ��еĹ�����ֿ�����
        //set_npcs_rate(50);

	//�Թ��������BOSS��
        set_exit_npcs(__DIR__"npc/0005/zhuangzhu4");

	//�Թ��ĵ��߳�
        set_maze_long(6); 

        set_npcs_rate(66);
        
        //set_lonely_create(1);


        set_maze_boxs(2);
        set_maze_traps(4); 

	//��ڷ���(�����ڶ���)
	set_entry_dir("north");

	//�������������ӷ���
	set_link_entry_dir("north");

	//�������������ӵ�����
	set_link_entry_room(__DIR__"vrm05out2");

	//��������������ӷ���
	set_link_exit_dir("south");

	//��������������ӵ�����
	set_link_exit_room(__DIR__"vrm05out3");

	//��ڷ��������
	set_entry_short("������");

	//��ڷ�������
	set_entry_desc(@LONG
���Ǹ����£�Զ���������ɮʱ������ɣ���ɮ��Ϊ�˱ܻ�������
�˺ܶ�ص����ڡ��������ҷ������ܣ����⹲�а���49�������ɷ�Բ֮
��Ī��͵�룬������Ǿ�Ϊ���ߺ��������ܳ�Ѩ��
LONG
);

	//BOSS���������
	set_exit_short("������");

	//BOSS��������
	set_exit_desc(HIB"
���Ǹ����£�Զ���������ɮʱ������ɣ���ɮ��Ϊ�˱ܻ�������
�˺ܶ�ص����ڡ��������ҷ������ܣ����⹲�а���49�������ɷ�Բ֮
��Ī��͵�룬������Ǿ�Ϊ���ߺ��������ܳ�Ѩ��
"NOR);

	//�Թ�����Ķ�����
	set_maze_room_short("������");

	//�Թ����������������ж�������������ÿ����
	//���ʱ���������ѡ��һ����
	set_maze_room_desc(@LONG
���Ǹ����£�Զ���������ɮʱ������ɣ���ɮ��Ϊ�˱ܻ�������
�˺ܶ�ص����ڡ��������ҷ������ܣ����⹲�а���49�������ɷ�Բ֮
��Ī��͵�룬������Ǿ�Ϊ���ߺ��������ܳ�Ѩ��
LONG
);


        // �Թ��ݻ�ʱ��
        set_remove_time(3000); 

	// �Թ������Ƿ�Ϊ���ⷿ�䣿
	set_outdoors(0);
}