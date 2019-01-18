// transfer.c
#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{
  int neiligain, manacost, diff;
  int eff, forcelev, spellslev, mymaxmana, mymaxforce;
  int myforce, mymana, temp;
  
  if(!target) target=me;    
  if( target != me ) return notify_fail("��ֻ���Է����ָ��Լ���������\n");
  
  forcelev=me->query_skill("force");
  if (forcelev > 300) forcelev=300;
  spellslev=me->query_skill("spells");
  if (spellslev > 300) spellslev=300;
  if( spellslev < 20 ) return notify_fail("��ķ�����Ϊ̫�͡�\n");
  if( forcelev < 20 ) return notify_fail("����ڹ���Ϊ̫�͡�\n");
  mymana=me->query("mana");
  if( mymana< 50 ) return notify_fail("��ķ��������ˡ�\n");
  
  mymaxforce=me->query("max_force");
  myforce=me->query("force");
  diff = mymaxforce - myforce;
  if( diff<1 ) return notify_fail("������������ӯ��\n");
  
  manacost = diff;
  if( manacost>mymana) manacost = mymana;
  
  me->add("mana", -manacost);
  mymaxmana=me->query("max_mana");
  neiligain = manacost*mymaxmana/(1+mymaxforce);
  if (neiligain>manacost) neiligain=manacost;
  //here, the more the max_force, the less the neili gain.
  eff=forcelev;
  if (eff>spellslev) eff=spellslev; // max eff is 300 right now
  eff=eff/3; // max eff is 100 now
  temp=100-eff; // temp ranges also from 0 to 100
  temp=temp*temp/100; // now still 0 to 100, but curved with the square.
  eff=(100-temp)*80/100; // rescale to max 80%
  neiligain=neiligain*eff/100;
  me->add("force", neiligain);
  if(wizardp(me) && me->query("env/combat")=="verbose")
    tell_object(me,GRN "�� "+manacost+" �������õ� "+neiligain+" ��������Ч��Ϊ "+eff+"��\n"NOR);
  if(me->query("force")>mymaxforce)
    {
      me->set("force", mymaxforce);
      //to prevent possible bug, set neili always smaller than max neili.
    }
  
  message_vision("$N�����ֹ��˼��䣬����������ӯ���ˡ�\n", me);
  
  if(me->is_fighting())me->start_busy(1);
  else me->start_busy(random(30/me->query_kar()));
  
  return 1;
}
