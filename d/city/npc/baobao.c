 //����npc
inherit F_VENDOR_SALE;


//inherit NPC;

#include <ansi.h>
int give_wx();
int give_wx2();
int answer_me();

void create()
{
         set_name(HIC"�񱦱�"NOR, ({"baobao"}));
   set ("long", @LONG
���������︺�����ҷ���ѧ�����Ŀɰ����񱦱���
(ask baobao about ����)��(ask baobao about 150��)
150����ѧ����������190��֮ǰҪ���������Ը���
ÿ����ѧ����ֻ�����ƽ𡢵��С�Ǳ�ܣ���������ѧ��
LONG);
           set("gender", "����");
        set("title",HIY"���ÿɰ���"NOR);
        set("age", 28);
        set("per", 40);
        set("attitude", "peaceful");
        set("vendor_goods", ([
                "whip":    "/d/obj/stey/yaowhip1.c",
                "hammer":    "/d/obj/stey/tianhammer.c",
                "sword":    "/d/obj/stey/sttt.c",
                "fork":    "/d/obj/stey/shenfork.c",
                "spear":    "/d/obj/stey/shenspear.c",
                "stick":    "/d/obj/stey/tianbang.c",
                "mace":    "/d/obj/stey/goldjian.c",
                "qin":    "/d/obj/stey/moqin.c",
                "blade":    "/d/obj/stey/guiblade.c",
                "staff":    "/d/obj/stey/shenstaff.c",
        ]) );
        set("inquiry", ([
            "����"    :(:give_wx:),
            "��ѧ����"    :(:give_wx:),
            "50��"    :(:give_wx:),
            "150��"    :(:give_wx2:),
   ]));
        setup();
        carry_object("/d/lingtai/obj/faguan")->wear();
}
int answer_me()
{
        command("say С���ұ��㣡�ٺ� ��\n");
        return 1;
}
int give_wx()
{
        object who=this_player();
        if (!userp(who)){
                command("heng");
                  command("say ʲôСèС��Ҳ��Ҫ����?");
                command("qi");
                return 1;
        }

         if (who->query("combat_exp") < 500000 ){
                command("hammer "+who->query("id") );
                command("say ����Ŭ��Ŭ�����ܿ�����ý����ġ�");
                command("addoil "+who->query("id") );
                return 1;
         }
         if (this_player()->query("jjj") > 0 ){
         message_vision("$N����$n����һ����\n",this_object(),this_player());
                command("say ����ֻ��һ�ݣ�����Ͳ����ˣ�\n");
        return 1;
        }
        who->add("potential",50000);
        who->add("daoxing",50000);
        who->set("jjj",1);
message_vision("$N����$n���ص�Ц��Ц��$n�������巢�����ҵı仯����ʱ�ε��ڵء�\n",this_object(),this_player());
        command("tell "+who->query("id")+"
            ���Ǳ��������50000! \n
             ��ĵ�����������ʮ��! \n");
          command("chat ��ϲ��ϲ��"+who->query("name")+"��ѧ����50�򣬸��轱����");
        return 1;
}
int give_wx2()
{
        object who=this_player();
        if (!userp(who)){
                command("heng");
                  command("say ʲôСèС��Ҳ��Ҫ����?");
                command("qi");
                return 1;
        }

         if (who->query("combat_exp") < 1500000 ){
                command("hammer "+who->query("id") );
                command("say ����Ŭ��Ŭ�����ܿ�����ý����ġ�");
                command("addoil "+who->query("id") );
                return 1;
         }
         if (who->query("combat_exp") > 2000001 ){
                command("hammer "+who->query("id") );
                command("say �㶼��ô����������Ҫ��̰�ģ���");
                command("kick "+who->query("id") );
                return 1;
         }
         if (this_player()->query("jjjj") > 0 ){
         message_vision("$N����$n����һ����\n",this_object(),this_player());
                command("say ����ֻ��һ�ݣ�����Ͳ����ˣ�\n");
        return 1;
        }
        who->add("potential",80000);
        who->add("daoxing",100000);
        who->set("jjjj",1);
message_vision("$N����$n���ص�Ц��Ц��$n�������巢�����ҵı仯����ʱ�ε��ڵء�\n",this_object(),this_player());
        command("tell "+who->query("id")+"
               ���Ǳ��������80000!\n
               ��ĵ���������һ����!\n
            \n");
          command("chat ��ϲ��ϲ��"+who->query("name")+"��ѧ����150�򣬸��轱����\n");
        return 1;
}
/*
void init()
{
     call_out("greeting", 1, this_player());
      ::init();
   add_action("do_vendor_list", "list");
}
*/
void init()
{
//      call_out("greeting", 1, this_player());
//      ::init();
        add_action("do_vendor_list", "list");
        add_action("do_fight", "fight");
        add_action("do_kill", "kill");
        add_action("do_cast", "cast");
        add_action("do_bian","bian");
        add_action("do_cast", "perform");
        add_action("do_steal", "steal");

}

int do_kill(string arg)
{
        object who = this_player();
        object me = this_object();

        if(!arg || present(arg,environment(me))!=me) return 0;

        message_vision("$N��$n��в�������ɱ�ң�������ˣ�\n", me, who);
        return 1;
}

int do_bian(string arg)
{
        object who = this_player();
        object me = this_object();

        if(!arg || present(arg,environment(me))!=me) return 0;

        message_vision("$N�ٺټ�Ц�˼���������С�����ޣ�\n", me);
        return 1;
}

int do_cast(string arg)
{
        object who = this_player();
        object me = this_object();
//         if(!arg || present(arg,environment(me))!=me) return 0;
        message_vision("$N��$n��в�������ɱ��ʦ��������ˣ�\n", me, who);
        return 1;
}
int do_steal(string arg)
{
  object who = this_player();
  object me=this_object();

  //if(!arg || present(arg,environment(me))!=me) return 0;

  message_vision ("$NͻȻ��$nЦ��������ͬ�����ˣ��α��أ�\n",me,who);
  message_vision ("$N�������鱩¶���ŵý������˻�ȥ��\n",who);
  return 1;
}


int do_fight(string arg)
{
        object who = this_player();
        object me = this_object();

        if(!arg || present(arg,environment(me))!=me) return 0;

        message_vision("$N��$nҡ��ҡͷ���㲻���Ҷ��֣�����\n", me, who);
        return 1;
}
void die()
{
  if (environment())
    message("sound", "\n\n�񱦱�������Цһ�����һ����ٻ����ģ�\n\n", environment());

  set("eff_kee", 1000);
  set("eff_gin", 1000);
  set("eff_sen", 1000);
  set("kee", 1000);
  set("gin", 1000);
  set("sen", 1000);
  set("force", 1000);
  set("mana", 1000);
}

void unconcious()
{
  die ();
}


