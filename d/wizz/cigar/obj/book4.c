// talk.c  ��
// by cigar
// Write by cigar

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
        set_name( HIW "���y �Z��" NOR , ({ "luan yu","luanyu", }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long" ,HIG
        "��Ĺ����׼�������һ�������������������������������...���ˣ���������ˣ��Թ�ͷ�ˡ�\n"NOR);
          set("value", 10000000);
                set("no_sell", "����Ŷ����������������!\n");
                set("material", "paper");
        }
}
void init()
{
  if (!wizardp(this_player())) {
                set("no_sell", "����Ŷ����������������!\n");
                set("no_drop", "��ǧ���ƽ��㲻����һ�ᣬ�ٺ�!\n");
                set("no_give", "���ˣ�˵���˾���׬���Ǯ������\n");
                set("no_get", "����û�а����Ķ���������...\n");
                set("no_put", "����������ˣ���ʦ��Ͳ��Թ��ˣ����Ǳ��������...����..\n");
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
  if( (int)me->query_skill("talk",1)>100 )
    return notify_fail("�Ͽ�ȥ��ڶ���<<�ϻ���ƪ>>��ɣ��ٶ�Ҳ�������㳤�����١�\n");
//:        if( (int)me->query_skill("talk",1)<2 )
//:                return notify_fail("�����ڻ�����˵����ô�������ĸ����������\n");
        if( environment(me)->query("no_fight") )
                return notify_fail("���ڰ�ȫ��������������������֪����С��û������飬����վ��ѩɽ���ϳ�ʹ����������ǧ���ƽ�\n");

        if( environment(this_object())!=me ) return notify_fail("�����̵ģ���Ҫ����������������Сʱ���ǲ��Ǳ����ֳ�ײ��?~\n");
  exp=(int)me->query("combat_exp");
  feitianlev=(int)me->query_skill("talk", 1);
  if(exp < 1000000)
    return notify_fail("�����ѧ��������������ѧ�ˡ�\n");
  sen_cost=30+(60-(int)me->query_int())+(50-(int)me->query_kar());
  if( (int)me->query("sen")<sen_cost )
    return notify_fail("����ˣ��ٶ����ҪĪ����������ˣ���ʱ������ʦ�����������˻���\n");     
        me->receive_damage("sen", sen_cost);
  
  gain = (int)me->query_skill("literate", 1)/3;
  gain -= random((int)me->query_int());
  gain += random(me->query_kar());
  if (gain <= 0) gain = 1;
  me->improve_skill("talk", gain);

        message_vision("$N��������һ�������������Ĳ�֪����˵ʲô��������\n", me);
  tell_object(me, "��˵���ļ�������ˣ�ѽѽѧ���ʱ����ȥ�ˡ�\n");

  return 1;
}
