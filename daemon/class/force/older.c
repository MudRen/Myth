#include <ansi.h>
inherit SSERVER;
int exert(object me, object target)
{
  int age,gain,mana,makeuplev;
  makeuplev=me->query_skill("makeup",1);
  if (me->query("daoxing")<100000)
    return notify_fail("��ĵ��в�����\n");
  if (makeuplev<100) 
    return notify_fail("�����������û��ѧ���ҡ�\n");
  mana=me->query("sen");
  if(mana<50) return notify_fail("��ľ��������ˡ�\n");
  me->add("sen", -50);
  age=me->query("age");
  write(HIG"���Ŀ���񣬾����ƺ��곤��Щ��\n"NOR);
  gain=(makeuplev-99)*10;
  me->add_temp("age_modify",gain);
  me->improve_skill("makeup",1,0);
  me->update_age();
  return 1;
}
