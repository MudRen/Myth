#include <ansi.h>

inherit NPC;
string *wang=({"qingguang","songdi","chujiang","chuguan","pingdeng",
              "dushi","taishan","lunzhuan","biancheng","yanluo",
             });
mapping name=(["qingguang":"�ع���","songdi":"�ε���","chujiang":"������",
  "chuguan":"������","pingdeng":"ƽ����","dushi":"������","taishan":"̩ɽ��",
  "lunzhuan":"��ת��","biancheng":"�����","yanluo":"������" ]);

string get_next(object);

void init() {
  object me=this_object();
  add_action("do_complain","complain");
  add_action("do_kill","kill");

  if (query_temp("target")==this_player()) {
    me->set("eff_kee",1000);
    me->set("kee",1000);
    me->set("sen",1000);
    me->set("eff_sen",1000);
  me->set("daoxing",2000000);
  me->set("combat_exp",2000000);
  me->set("force",2000);
  me->set("max_force",2000);
  me->set("max_mana",2000);
  me->set("mana",4000);
  me->set("force_factor",120);

}
  ::init();
}

int do_complain(string arg) {
  object ob=this_player();
  object me=this_object();
  string complainee=ob->query_temp("dntg_hell/next");
  if (!arg) return notify_fail("��Ҫ��˭���ߣ�\n");
  if (me!=present(arg,environment(me)) ) return 0;
  
  
  message_vision("$N����$n�е�����"+RANK_D->query_self_rude(ob)+
    "���ѳ�������֮�⣬��������֮�У��Ѳ�����˾��Ͻ����ô�������ң���\n"NOR,ob,me);
  ob->command("bug "+me->query("id"));

  if (!complainee) {
    message_vision("\n$N������üͷ����$n˵����������������;��"+
      "�Ҳ�����˽����ڤ֮�Ҳ�����ˡ�����������£���\n\n",me,ob);
    return 1;
  }
  if (name[complainee]!=me->name()) {
    message_vision("\n$N������üͷ����$n˵���������·��Ҿ��֣�"+
      "ԩ��ͷ��ծ�������ĸ�ǲ�˹��㣬��ȥ���ĸ��ɡ���\n\n",me,ob);
    ob->set_temp("dntg_hell/next",get_next(me));
    return 1;
  }
  ob->delete_temp("dntg_hell/ready");  
  message_vision("\n$N���߳�ŭ����������������������˭�����㵽�����"+
        "������������ȥ�����й٣���\n",me);
  me->set_temp("target",ob);
  me->kill_ob(ob);
  return 1;
}

string get_next(object me) {
  string who=wang[random(10)];
  while (name[who]==me->query("name"))
     who=wang[random(10)];
  return who;
}

void kill_ob(object ob) {
  object target=query_temp("target");
  if (target!=ob) delete_temp("target");
  ::kill_ob(ob);
}  
void unconcious() {die();}
void die() {
  object me=this_object();
  object ob=me->query_temp("target");
  string next;

  if (!objectp(ob)) {
    ::die();
    return;
  }
  ob->set_temp("dntg_hell/"+me->name(),1);
  message_vision(HIW"\n$N˵�����������ˣ������ˣ���Ͷ��....����\n\n"NOR,me);
  me->remove_killer(ob);
  me->remove_enemy(ob);
  ob->remove_killer(me);
  ob->remove_enemy(me);
  me->set("kee",(int)me->query("max_kee"));
  me->set("eff_kee",(int)me->query("max_kee"));
  me->set("sen",(int)me->query("max_sen"));
  me->set("eff_sen",(int)me->query("max_sen"));
  me->clear_condition();
  
  me->command("say "+ob->name()+RANK_D->query_respect(ob)+
       "��ͨ���С���ʰ��·硣");
  next=get_next(me);
  ob->set_temp("dntg_hell/next",next);
  message_vision("$N���˷����ϵ����飬��$n˵������������"+name[next]+
   "�������ˣ�ҪС������"+RANK_D->query_respect(ob)+"��"+RANK_D->query_respect(ob)
   +"����ȥ�������۰ɡ�\n\n",me,ob);

  if (ob->query_temp("dntg_hell/"+name[next]) ) 
      ob->set_temp("dntg_hell/ready",me);      
}

int do_kill(string arg) {
  object me=this_object();
  object ob=this_player();
  string next=ob->query_temp("dntg_hell/next");

 if(!userp(ob)) return 1;
  if ( !arg) return notify_fail("����ɱ˭��\n"); // added by mudring@sjsh......
  if (me!=present(arg,environment(me))) return 0;
  if (ob->query_temp("dntg_hell/ready")!=me) return 0;
  if (ob->query("dntg/hell")=="done") return 0;
  if (!next) return 0;

   message_vision("$N�İ���У�����ô����"+name[next]+
        "���������������ˣŪ���ң�����������\n\n",ob);

   message_vision("$N�ŵû����ɢ������˵�������˰��ˣ����㣬�����㡣��\n",me);
   message_vision("$N�Ӱ����ó���������������ʣ���պŨī����$n�����ֻ�ȥ��\n\n",me,ob);

   ob->set("dntg/hell","done");
   me->command("chat "+ob->name()+"��"+RANK_D->query_rude(ob)+
     "��ǿ���ף������л���������ɭ��ǿ�����ţ���������������ۣ��������㣡");
   me->delete_temp("target");
  ob->set("life/no_death_decrease",1);
   ob->delete_temp("dntg_hell");
   
   return 1;
}
