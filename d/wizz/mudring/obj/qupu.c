#include <ansi.h>
#include <command.h>

inherit ITEM;
inherit F_AUTOLOAD; 
#include "songs.c"

void create()
{
        set_name(YEL "����" NOR, ({ "qu pu", "pu"}));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else{
                set("unit", "��");
                set("long", "
һ���Ѷ����������ף�����Գ�(chang)��������ӣ�

  ��ԲԲ����(yuanyuan_qu)
  ����������(wanghai_chao)
  ��������  ��Ϊ���(wenshi_jian)
  ����������(dielian_hua)
  ����˹С����(bosi_xiaoqu)
  ����������ҹ��(chunjiang_huayueye)
  �������ǿ��С�(yinma_changcheng)
  �������ơ�(jiangjin_jiu)
  ��Ц��������(xiaoao_jianghu)
  ����ѩ�������йٻؾ���(baixue_ge)
  �������ˡ�(yu_meiren)
  ���������������ʹ��� (song_chun)
  ��ӽ�ɡ� (yong_he)
  ��ˮ����ͷ������ �� (shuidiao_getou)
  �������졷 (manjiang_hong)
  �������塷 (yulin_lin)
  ��һ��÷�� (yijian_mei)
      
��������ó��ò��ã�����ͣ(ting)�£��ٻ�ȥ������
\n");
                set("value", 10000);
                set("material", "silk");
             }
        setup();
}


void init()
{
        add_action("do_sing", "chang");
        add_action("do_halt", "ting");
}
int do_halt()
{
        if (find_call_out("sing_stage") < 0) return 0;
        this_player()->delete_temp("qupu");
        message_vision(HIR"\n$N���ִ��һ��ʹ��ı��飬���εؿ�����������ͣ����������\n"NOR, this_player());
        remove_call_out("sing_stage");
              return 1;
}
int do_sing(string arg)
{
       object me, ob; 
       int i = sizeof(qupu);
       int stage;
       stage = 0;
       me = this_player();
       ob = this_object();
       if (find_call_out("sing_stage") >= 0) return notify_fail("����ͬʱ������������\n");
       if(!arg) return notify_fail("���볪ʲô��\n");
        while (i--) if (arg == qupu[i]["name"]) break;
        if (i<0) return notify_fail("�����ﻹû�����볪�����ӡ�\n");
        if(me->is_busy())
           return notify_fail("����æ���ء�\n");
        if(me->query_temp("qupu")) return notify_fail("�����ڳ����ء�\n");
        if(me->query("gender") != "����"){
          if(present("dong xiao", me))
             message_vision(MAG
"$N����$n"MAG"������ӯӯ�����񴽺��ֻ����
����������ת��������������������΢���𴦣�����ˮ�����졣
����$N΢΢һЦ��������ʼ������\n\n"NOR, me, ob);
          else message_vision("$N����$n������ӯӯһ�ݣ�Ȼ��������ʼ������\n\n"NOR, me, ob);
          }
        else {
          if(present("yao qin", me))
             message_vision(BLU"$N����$n"BLU"����ϥ���£������ٷ���ϥ�ϣ����ҵ��ϣ��������ң�����������\n\n"NOR, me, ob);
          else message_vision("$N����$n���ſ����ѽѽѽ����������\n\n"NOR, me, ob);
          }
      me->set_temp("qupu", 1);
      call_out("sing_stage", 2, me, stage, i, sizeof(qupu[i]["context"]));
      return 1;
}

void sing_stage(object me, int stage, int i, int size)
{
   if(stage < size) {
   message_vision(qupu[i]["context"][stage], me);
   me->start_busy(1);
   call_out("sing_stage", 1, me, ++stage, i, size);
   }
   else {
    me->delete_temp("qupu");
    if(me->query("gender") != "����"){

      if(present("dong xiao", me))
          message_vision(MAG"\n����һ�ᣬ$N�����������ᣬ�ƺ���ˮ����Զȥ�����ڸ������գ���Ȼ������\n"NOR,me);
      else message_vision("\n$N����ת�ߣ��������һ�֣�����ȴ��Ȼ�����������ڿ������ص���������\n", me);
          }
    else {
      if(present("yao qin", me))
         message_vision(BLU"\nֻ������ֹЪ��$N����һ����վ���������������˸��ϡ�\n"NOR, me);
      else message_vision("\n$N�������һ�֣�����һ����Х��Х��ԶԶ���˿�ȥ��\n", me);
          }
    }
}

int query_autoload()
{
return 1;
}

