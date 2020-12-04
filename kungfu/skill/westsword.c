inherit SKILL;
#include <ansi.h>;

mapping *action = ({
   ([   "action":
"$N����$w��$n��$lֱ��������",
     "dodge":     1000,
     "parry":                300,
     "damage":     200,
     "damage_type":   "����"
   ]),
   ([   "action":
"$N����$w��$n��$lб��������",
     "dodge":     1000,
     "parry":                300,
     "damage":     200,
     "damage_type":   "����"
   ]),
   ([   "action":
"$N���е�$w����һ�����ǣ���$n��$l���˹�ȥ��",
     "dodge":     1000,
     "parry":                300,
     "damage":     200,
     "damage_type":   "����"
   ]),
   ([   "action":
"$N���е�$w���˸���Բ����$n��$l���˹�ȥ��",
     "dodge":     1000,
     "parry":                300,
     "damage":     200,
     "damage_type":   "����"
   ]),
   ([   "action":
"$N���е�$w����$n��$l���˹�ȥ��",
     "dodge":     1000,
     "parry":                300,
     "damage":     200,
     "damage_type":   "����"
   ]),
});

int valid_learn(object me)
{
   object ob;

   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "sword" )
     return notify_fail("���������һ�ѽ�������������\n");

   return 1;
}

int valid_enable(string usage)
{
   return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        int i, level;
        if (!me) me = this_object();
        level   = (int) me->query_skill("westsword",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
        {
   if( (int)me->query("kee") < 30
   ||   (int)me->query("force") < 3 )
     return notify_fail("�����������������û�а취��ϰ���󽣷���\n");
   me->receive_damage("kee", 30);
   me->add("force", -3);
   //write("�㰴����ѧ����һ�����󽣷���\n");
   return 1;
}


mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        if( damage_bonus > 100 ) 
{
        victim->receive_wound("qi", damage_bonus );
        return HIR "����ȭ!!һ��ȭӰ������һ����Ѫ��$n���������\n" NOR;	
}
        if( damage_bonus < 75 ) 
{
        victim->receive_wound("qi", damage_bonus );	
        return YEL "����ȭ!!һ��ȭӰ������$n�ƺ�һ��,���ӻ������Σ�\n" NOR;
}
else
{       
        victim->receive_wound("qi", damage_bonus );	
        return HIM "����ȭ!!һ��ȭӰ��������������������һ�����죬���Ͼ�����һЩѪ�Σ�\n" NOR;
}

}