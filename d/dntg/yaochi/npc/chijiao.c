
#include <ansi.h>

inherit NPC;

string ask_pantao();

void create()
{
        set_name("��Ŵ���", ({"chijiao daxian","daxian"}));
        set("long", @LONG

һ������ɢɢ����ͷ���������Ž��Ĵ��ε���
������ȥ�Һ���ʵ�����һƭ(pian)���ϵ���
LONG);

        set("attitude", "peaceful");
        
    set("combat_exp", 500000);
  set("daoxing", 800000);


        set("age", 50);
        set("per", 22);
        set("str", 30);
        set("int", 30);
        set("cor", 30);
        set("cps", 30);
        set("con", 30);
        set("class", "xian");
        set("rank_info/respect", "������");
        set("max_kee", 1000);
        set("max_sen", 1000);
        set("force", 800);
        set("max_force", 800);
        set("force_factor", 50);
        set("max_mana", 800);
        set("mana", 800);
        set("mana_factor", 50);


        set_skill("spells", 120);
        set_skill("taiyi", 120);
        set_skill("force",120);
        set_skill("zhenyuan-force",120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("baguazhen", 120);
        set_skill("unarmed", 120);
        set_skill("wuxing-quan", 120);
        set_skill("staff",110);
        set_skill("fumo-zhang",120);
        map_skill("spells", "taiyi");
        map_skill("force", "zhenyuan-force");
        map_skill("dodge", "baguazhen");
        map_skill("unarmed", "wuxing-quan");
        map_skill("staff", "fumo-zhang");
        map_skill("parry", "fumo-zhang");
        setup();
        carry_object("/d/obj/cloth/baipao")->wear();
       set("inquiry", ([
                "name"     : "�Ϸ��Ŵ�����Ҳ��",
                "here"     : "������������",
                "pantao" : (:ask_pantao:),
                "��һ�" : (:ask_pantao:),
         ]) );

        set("chat_msg", ({
            "��Ŵ���̾������ô��û������һ�����ӣ��Ϸ򶼵Ȳ����ˡ�\n",
            (: random_move :),
            (: random_move :),
            (: random_move :),
        }) );
        set("chat_chance", 10);
}
void init()
{
  object ob;
  ::init();
  this_player()->delete_temp("ask_chijiao_daxian");
  add_action("do_pian","pian");
 
}
string ask_pantao() {
  this_player()->set_temp("ask_chijiao_daxian",1);  
  return "��Ҵ���ٿ��ڼ����Ϸ�����ĸ���У�ȥ����Ҽλᡣ";
}

int do_pian(string arg) {
  object me=this_object();
  object liar=this_player();
  object letter;

  string *msg=
   ({"��˵��ĸ��������ĸ��ʧ�ͣ���ĸ�����ˣ�����������һ᲻���ˡ�",
     "��֪���������������������Ӹ�ٵ�����ۺ�����������̫�׽��ǵ����ء�",
     "�½��и���ʲô�ļһ��Ȼһҹ��׬����һǧ��ĵ��У��϶��У£գǣ�",
     "����������һ��ֻ��һǧ�����ķ������Ӵ���ˣ��涪����",
     "��˵�½������˸�У��������ɲ�ȥ�������֣�",
     "��˵�и���Χ��ľ�Ȼ��֤���ˣ����������ĵ�������������",
  });
  if (arg!="daxian" && arg!="chijiao daxian") 
     return notify_fail("����ƭ˭��\n");
  
  if (me->query_temp("just_pian")) 
     return notify_fail("ƭ�˵Ļ�˵��̫��Ͳ����ˣ��������˵��\n");
  me->set_temp("just_pian",1);
  call_out("remove_pian",5,me);

  if (!liar->query_temp("ask_chijiao_daxian")) {
    message_vision("$N��������Ķ�$n˵����"+msg[random(sizeof(msg))]+
          "��\n",liar,me);
    if (random(2)) {
      command("ah");
      command("say ���д��£�����������֮�����䲻�С�");
      command("sigh2");
    } else {
        command("laugh");
        command("say ����"+RANK_D->query_rude(liar)+
          "�������ң��������д��£����Ų��š�");
        command("shake");
      }
    return 1;
  }
  liar->command("say ������������֪�������"+RANK_D->query_self(liar)+ 
                "��·������λ������ͨ���������񣬺�ȥ���硣��");
  if (liar->name()==me->name()) {
    command("hmm");
    command("say ������Ϸ�ģ������˵������Ī��������թ��������������ۣ���������");
    command("wave");
    message_vision(HIY"$N��һָ������һ���Ʋʣ��߸����˵�������ȥ��\n�ٴ�һ�����ڣ���֮����ȽȽ�����𡣡���\n\n"NOR,me);
    destruct(me);
    return 1;
  }
  
  command("ok");   
  command("say ���������������л���������ȥͨ�������񣬷�ȥ���ظ��᣿");
  command("shrug");
  message_vision(HIY"$N��һָ������һ���Ʋʣ��߸����˵�������ȥ��\n�ٴ�һ�����ڣ���֮����ȽȽ�����𡣡���\n"NOR,me);
  letter=new(__DIR__"obj/letter");
  if (letter->move(liar))
    message_vision(HIY"$N�ߵô�æ�������ڲ���������ֽƬ��$n�����ֿ죬һ�ѽ�ס�����ڻ��\n"NOR,me,liar);
  destruct(me);
  return 1;
}

void remove_pian(object me) {
  me->delete_temp("just_pian");
}
