// talk.c  ��
// by cigar
// Write by cigar

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
        set_name( HIG "��֪����Ҳ��" NOR , ({ "zhihu zheye","zhzy", }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long" ,HIG
        "�������ܲ��ܶ��������˷�����ǧ���ƽ�Ŷ��������������û����...\n"NOR);
          set("value", 3000000);
                set("no_sell", "����Ŷ����������������!\n");
                set("material", "paper");
        }
}
void init()
{
  if (!wizardp(this_player())) {
                set("no_drop", "���Ǯ����Ǯ�����ű�����ǽ��鰡������!\n");
                set("no_give", "������ˣ�˵���˾���׬���Ǯ���������������Ұ���������\n");
                set("no_sell", "�����̵����������Ŷ����������������!\n");
                set("no_get", "���˻�Ǯ�����ã�������������=0��\n");
                set("no_put", "�㻹Ҫ���ţ�ʡʡ�ɣ�������\n");
}
  add_action("do_read", "read");
}

int do_read(string arg)
{
  object me=this_player(),book=this_object();
  int sen_cost, gain,feitianlev,exp;

  if( !book->id(arg) ) return notify_fail("��Ҫ��ʲô��\n");
  if(me->is_busy()) return notify_fail("������æ���أ����ǵȾ��������ٶ���ɣ�\n");
  if(me->is_fighting()) return notify_fail("���ڲ�����飬̫���˰ɣ�����\n");
  if( (int)me->query_skill("talk",1)>250 )
    return notify_fail("����ˣ��ٶ������ͷ��Ҫ����ˡ�\n");
        if( (int)me->query_skill("talk",1)<151 )
     return notify_fail("������˵�������Ͱ���ô֪����Ҳ���ܲ��ˣ���ȥ��ɱ�ɡ�\n");
        if( environment(me)->query("no_fight") )
                return notify_fail("���ڰ�ȫ��������������������ʦ֪����С��û������飬����վ��ѩɽ���ϳ�ʹ����������ǧ���ƽ�\n");

        if( environment(this_object())!=me ) return notify_fail("�����̵ģ���Ҫ����������������Сʱ���ǲ��Ǳ����ֳ�ײ��?~\n");
  exp=(int)me->query("combat_exp");
  feitianlev=(int)me->query_skill("talk", 1);
  if(exp < 1000000)
    return notify_fail("�����ѧ��������������ѧ�ˡ�\n");
  sen_cost=20+(40-(int)me->query_int())+(35-(int)me->query_kar());
  if( (int)me->query("sen")<sen_cost )
    return notify_fail("����ˣ��ٶ����ҪĪ����������ˣ���ʱ������ʦ�����������˻���\n");     
        me->receive_damage("sen", sen_cost);
  
  gain = (int)me->query_skill("literate", 1)/3;
  gain -= random((int)me->query_int());
  gain += random(me->query_kar());
  if (gain <= 0) gain = 1;
  me->improve_skill("talk", gain);

        message_vision("$N����֪����Ҳ�����������\n", me);
  tell_object(me, "��˵���ļ�������ˣ�\n");

  return 1;
}
