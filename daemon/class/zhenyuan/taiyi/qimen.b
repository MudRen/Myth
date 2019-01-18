#include <ansi.h>
inherit SSERVER;
#define WIND_FILE "/d/jjf/obj/wind_seal.c"
void get_out(object where);
int cast(object me, object target)
{
  string msg,dest,dir;
  object sleeveroom,qimen;
  string sname;
  object env=environment(me);
  object bagua=present("bagua fu",me);
  seteuid(getuid());
  if (me->query_skill("taiyi",1)<60)
     return notify_fail("���̫���ɷ����������졣\n");
  if (!bagua) 
    return notify_fail("������û�а��Է�������ʩչ���Ŷݼס�\n");
  dir=bagua->query("dir");
  if (!dir) return notify_fail("��������ڰ��Է���ָ��<direct>ʩ���ķ���\n");
  dest = environment(me)->query("exits/"+dir);
  if(!dest) return notify_fail("�������û��·����\n");
  if (!env->valid_leave(me,dir))
     return notify_fail("�㲻�ܳ��������ʩչ���Ŷݼס�\n");
  sleeveroom=load_object("/d/wiz/sleeveroom");
  if(!sleeveroom) return notify_fail("��ʧ���ˡ�\n");
  sname=me->query("id")+"'s qimen";
  if (me->query_temp("cast_qimen") || present(sname,sleeveroom))
    return notify_fail("���Ѿ���ʩչ���Ŷݼ����ˡ�\n");
  if( (int)me->query("mana") < 400 )
          return notify_fail("��ķ��������ˣ�\n");
  if( (int)me->query("sen") < (int)me->query("max_sen")/2 )
      return notify_fail("������ͷ�Բ����ѣ�����ʹ�ó����Ŷݼף�\n");
  if( random(me->query("max_mana")) < 50 ) {
       write("��ʧ���ˣ�\n");
       return 1;
  }
  if (me->is_busy())
    return notify_fail("����һ��������û����ɡ�\n");
  if(me->is_fighting())
    return notify_fail("����æ�Ŵ�ܣ�û�������Ŷݼס�\n");
   msg =  HIR "$Nߴ����������˼������ͻȻ����Ӱ������\n" NOR;
   message_vision(msg, me);
   me->add("mana", -400);
   qimen=new("/d/obj/fabao/qimennei");
   if(!qimen) return notify_fail("�ϣϣУӣ��°����������ˡ�\n");
   qimen->set_name(me->query("name")+"�����Ŷݼ���",({sname,"qimen"}));
   if(!qimen->move(sleeveroom)) 
      return notify_fail("�ϣϣУӣ��°����������ˣ�\n");
     me->receive_damage("sen", 100);
   if (!env) return notify_fail("�ϣϣУӣ��°����������ˡ�:(\n");
   env->set("altered_dir",dir);
   env->set("old_room",dest);
   env->set("exits/"+dir,qimen);
   qimen->set("host",me);
   if (me->move(qimen)) {
     if (me->ride()) me->ride()->move(environment(me));
     qimen->set("old_room",env);
     env=environment(me);
     qimen->set_exits(dest);
     me->set_temp("cast_qimen",1);
   }  
  me->start_busy(random(3));
  return 1;
}
