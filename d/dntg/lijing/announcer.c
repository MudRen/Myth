
#include <ansi.h>
inherit NPC;

void create() {

  set_name("̫�׽���",({"taibai jinxing"}));
  setup();
}

void announce(object winner,object env) {
  call_out("announce1",2,winner,env);
}

void announce1(object winner,object env) {

  if (winner->query("dntg/lijing")!="done") {
    command("chat �����ʥּ��"+winner->query("name")+RANK_D->query_respect(winner)+
                  "�书������������Ⱥ���ӷ�Ϊ�����ʥ��");
//    command("rumor ����֮�ˣ�ɥȨ������ҲҲҡ�����")
    winner->add("cor",2);
    tell_object(winner,HIC"��õ������㵨ʶ��\n"NOR);
    winner->set_temp("apply/title",({HIR"�����ʥ"NOR}));
   winner->set("dntg/lijing","done");
  env->set("host",winner);
  }

  destruct(this_object());
}
