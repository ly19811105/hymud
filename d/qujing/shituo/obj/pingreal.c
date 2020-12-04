// by snowcat 12/17/1997

#include <ansi.h>
#include <weapon.h>
 
inherit F_UNIQUE;
inherit ITEM;
void remove_npc(object victim);
 
void create()
{
      set_name("��������ƿ",({"yinyang erqi ping", "ping", "fabao"}));
  set_weight(5000);
  set_max_encumbrance(100000000000);
  if(clonep())
    set_default_object(__FILE__);
  else {
    set("unit","ֻ");
    set("value", 100000);
    set("material","cloth");
      set("long","��������������������������װ��ƿ�У�һʱ���̻�Ϊ��ˮ��\n");
  }
  set("no_get",1);
  set("no_fight", 1);
  set("no_magic", 1);
  set("unique", 1);
    set("no_sell", "��������ƿ�˷���û�˸���Ҳ��\n");
set("no_put",1);
    set("no_give", "��������ƿ�˷�����������Ҳ��\n");
    //set("replace_file", "/d/xueshan/obj/pingfake.c");
  set("is_monitored",1);
  setup();
} 

void init ()
{
add_action ("ji", "ji");
add_action ("ji", "cast");
  add_action ("do_out", "out");
}

int do_out ()
{
  object me = this_object ();
  object who = this_player();
  object where = environment (who);
  object room = environment (me);

  if (where != me)
    return 0;

  if (who->query_temp("no_move") ||
      who->is_busy())
  {
    tell_object (who, "�����������������ȥ��ȴŲ���������ӡ�\n");
    return 1;
  }
    tell_object (who, "�����ڹ⻬��ƿ���ϣ�һ���������ȥ��\n");
  if (room->is_character())
    room = environment (room);
  who->move(room);
    message_vision ("$N����������ƿ�����ͷ�������������˳�����\n",who);
  return 1;
}

int ji_ob (object victim)
{
  object ping = this_object ();
  object me = environment(ping);
  string pingname = ping->query("name");
  int damage, ap, dp, myspells, myexp, victimspells, victimexp, duration;
  int mykar=me->query("kar"), victimkar;

  if (me->is_busy())
  {
    tell_object (me, "���޷�æ��͵�м�"+pingname+"��\n");
    return notify_fail("����æ���ء�\n");
  }

  if (sizeof(all_inventory(ping))>0)
  {
    tell_object (me, pingname+"����������޷��ټ�"+pingname+"��\n");
    return notify_fail("���"+pingname+"ʧ�ܡ�\n");
  }

  if (!victim)
  {
    tell_object (me, "��������˲������\n");
    return notify_fail("���"+pingname+"ʧ�ܡ�\n");
  }

  if (!living(victim))
  {
    tell_object (me, victim->query("name")+"�Ѿ����޵ֿ����������ؼ��ˡ�\n");
    return notify_fail("���"+pingname+"ʧ�ܡ�\n");
  }

  if (!me->is_fighting())
  {
    tell_object (me, "ֻ��ս���в��ܼ�"+pingname+"��\n");
    return notify_fail("���"+pingname+"ʧ�ܡ�\n");
  }

  if (!victim->is_fighting())
  {
    tell_object (me, "ֻ��ս���в��ܼ�"+pingname+"��\n");
    return notify_fail("���"+pingname+"ʧ�ܡ�\n");
  }
  if (userp(victim) && userp(me))
  {
    tell_object (me, "���ܶ����ʹ�á�\n");
    return notify_fail("���ܶ����ʹ�á�\n");
  }
  if ((int)me->query("neili") < 500)
  {
    tell_object (me, "��ķ������㣬������"+pingname+"��\n");
    return notify_fail("���"+pingname+"ʧ�ܡ�\n");
  }

  if( (int)me->query("jing") < 500)
  {
    tell_object (me, "���޷����о��������\n");
    return notify_fail("���"+pingname+"ʧ�ܡ�\n");
  }

message_vision ("\n$N������������ͳ�"+pingname+"��"+victim->query("name")+"һָ..\n",me,victim);
  if (ping->query("interactive_usage") > (me->query("kar")/2))
  {
    message_vision ("ֻ�����顱��һ����"+pingname+"ͻȻ���˸����顣\n",me);
    destruct (ping);
    return notify_fail("���"+pingname+"ʧ�ܡ�\n");
  }
  me->start_busy(60/mykar);
  victimkar=victim->query("kar");
  myspells=me->query_skill("spells")/10;
  myexp=me->query("combat_exp")/1000;
  victimspells=victim->query_skill("spells")/10;
  victimexp=victim->query("combat_exp")/1000;
  ap=(myexp+myspells*myspells*myspells/3)*me->query("jing")/me->query("max_jing");
  ap=ap*mykar/1000;
  dp=(victimexp+victimspells*victimspells*victimspells/3)*victim->query("jing")/victim->query("max_jing");
  dp=dp*victimkar/1000;
  if (wizardp(me) && me->query("env/combat")=="verbose")
    tell_object(me, GRN "������"+ap+"�����أ�"+dp+"��\n" NOR);

  if(random(ap+dp)>dp)
  {
     int ratio;

     message_vision ("$n�ٸ�ͷ�ؽ��ᣬ�����ɼ���Ʈ��������\n",me,victim);
     message_vision ("���֮��$n��"+pingname+"�ȵ�һ��������˽�ȥ��\n",me,victim);
     victim->move(ping);
     duration = (50-victim->query("kar"))*10;
     if (duration < 60)
       duration = 60;
     victim->set_temp("no_move",1);
     victim->start_busy(15);
 
     if (!userp(victim)) 
{
//message_vision ("������ҡ����ƿ��"+victim->query("name")+"��ʱ��Ϊ��ˮ��ʧ��Ӱ��\n",me,victim);
// destruct(victim);
//victim->unconcious();
  call_out("remove_npc",random(10)+4,victim);
}
else
       victim->unconcious();
     ratio=75;
     if(victim) {//sometimes victim maybe lost after unconcious().
    
     call_out ("reviving",1,victim);
     call_out ("releasing",duration,victim);
     }
     me->add("neili", -400);
  }
  else
  {
      message_vision ("$nһת���ܿ���"+pingname+"������һ�У�\n",me,victim);
    me->add("neili", -200);
  }
  if (victim)
    victim->kill_ob(me);
  if (interactive(me))
    ping->add("interactive_usage",1);
  return 1;
}

void reviving (object who)
{
  object me = this_object();

  if(!who) return;
  if (! who->query_temp("block_msg/all"))
    return;

  if (environment(who) != me)
  {
    who->revive();
    who->start_busy(1);
    return;
  }
  call_out ("reviving",1,who);
}

void releasing (object who)
{
  object me = this_object();
  object room = environment(me);

  if (room->is_character())
    room = environment(room);

  if (! who)
    return;

  who->set_temp("no_move",0);
  who->interrupt_me();
  if (! who ||
      interactive (who))
    return;
  if (environment(who) != me)
    return;
  who->move(room);
    message_vision ("$N����������ƿ�����ͷ�������������˳�����\n",who);
}

int ji (string target)
{
  object ping = this_object ();
  object me = this_player();
  string pingname = ping->query("name");
  object victim;

  if (!target)
    return notify_fail("�����˭��"+pingname+"��\n");

  victim=present(target,environment(me));
  ping->ji_ob(victim);
  return 1;
}

 void remove_npc(object victim)
{
object me = this_player();
//  victim = this_object();
message_vision ("������ҡ����ƿ��"+victim->query("name")+"��Ȼ��Ϊ��ˮ��ʧ��Ӱ�ˣ�\n",me);
destruct(victim);
return;
}