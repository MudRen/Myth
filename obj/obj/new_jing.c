inherit NPC;
#include <ansi.h>
  int give_bonnet();
    int give_dan();
   int accept_object(object who, object ob)
{
                    if( (string)ob->query("id")=="loyal bonnet" )
{
who->set("yudian/bonnet",0);
                    command("say �ý�û����ٽ費�ѡ�");
    return 1;
}
}
void create()
{
                    set_name(HIB"ħ��С����"NOR, ({"jing ling","jing", "jingling"}));
   set ("long", @LONG
һ���ɰ���С���飬��׼���˺ܶ������(gift)�����Ŷ��
�����ϻ�����ʦ����(bonnet)��!
�������ȥ����(ask)�����ǵã���ʦ����������Ҫ��Ŷ��
LONG);
       set("gender", "Ů��");
          set("title",HIM"����"HIG"��Ե"NOR);
               set("age", 9);
        set("per", 40);
       set("attitude", "peaceful");
       set("shen_type", 1);
set("inquiry", ([
            "bonnet":(:give_bonnet:),
          "gift":(:give_dan:),
]));
        setup();
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
}
}
int give_dan()
{
object dan;
object who=this_player();
         if (this_player()->query("yudian/gift")=="got")
{
          message_vision("$N����$n����һ����\n",this_object(),this_player());
       command("say ����ֻ��һ�ݣ�����Ͳ����ˣ�");
  return 1;
}
dan=new("/u/yudian/new_dan");
  dan->move(who);
message_vision("С��������������������!\n$N��$nһ�����ɾ�����ң����\n",this_object(),this_player());
     who->set("yudian/gift","got");
return 1;
}
 int give_bonnet()
 {
 object bonnet;
 object who=this_player();
          if (this_player()->query("yudian/bonnet")=="got")
 {
           message_vision("$N����$n����һ����\n",this_object(),this_player());
          command("say �ϴθ���Ļ�û���أ������ˣ�");
   return 1;
  }
      bonnet=new("/d/lingtai/obj/faguan");
  bonnet->move(who);
  message_vision("С��������������������!С������һ����ʦ���ڡ�\n$N��$nһ����ʦ���ڡ�\n",this_object(),this_player());
      who->set("yudian/bonnet","got");
           command("say �����˼ǵû���Ŷ�������´β����ˣ�");
 return 1;
  }
void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
say(name()+"���ص�˵������Ҫ���������Ұ�����������ֻ��һ�λ���Ŷ����������\n");
}
