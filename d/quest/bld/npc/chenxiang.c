//
//npc--chenxiang

inherit NPC;
#include <ansi.h>

int ask_mother ();

void create()
{
  set_name( HIW "����" NOR, ({"chen xiang","chen", "xiang"}));
  set("title",HIC+"��֮��"+NOR);

  set("long", HIY"��ʥĸ˽����ͥ�ͷ�������֮�ӡ���˵�������ʴϻۣ��������ר�Ű�����С�ߣ�
��ʶ�����˶�ϲ������\n"NOR);

  set("gender", "����");
  set("attitude", "peaceful");
  set("class", "xian");
  set("age", 16);
  set("str", 40+random(10));
  set("int", 30);
  set("per", 26+random(4));
  set("con", 20);
  set("max_kee", 6000);
  set("max_sen", 6000);
  set("max_force", 20000);
  set("force", 20000);
  set("force_factor", 500);
  set("max_mana", 20000);
  set("mana", 20000);
  set("mana_factor", 500);
  set("combat_exp", 12000000);
  set("daoxing", 12000000);

  set("chat_chance_combat", 70);
  set("chat_msg_combat", ({
                (: cast_spell, "bighammer" :),
        }) );

  create_family("�Ϻ�����ɽ", 2, "����");


  set("inquiry", ([
    "��ʥĸ" : (: ask_mother :),
    "sanshengmu" : (: ask_mother :),
    "gshengmu" : (: ask_mother :),
    "ĸ��" : (: ask_mother :),
    "����" : (: ask_mother :),
   "mother" : (: ask_mother :),


  ]) );

  set_skill("force", 250);
  set_skill("unarmed", 250);
  set_skill("dodge", 250);
  set_skill("parry", 250);
  set_skill("staff", 250);
  set_skill("lotusforce", 250);
  set_skill("lunhui-zhang", 250);
  set_skill("jienan-zhi", 250);
  set_skill("lotusmove", 250);
  set_skill("spells",250);
  set_skill("buddhism",250);
  map_skill("spells","buddhism");
  map_skill("dodge", "lotusmove");
  map_skill("unarmed", "jienan-zhi");
  map_skill("staff", "lunhui-zhang");
  map_skill("parry", "lunhui-zhang");
  map_skill("force", "lotusforce");

  setup();
  
  add_money("gold", 2);

  carry_object("/d/obj/armor/jinjia")->wear();
  carry_object("/d/nanhai/obj/budd_staff")->wield();

}


void relay_emote(object ob, string verb)
{
        if( ob->query("id") == "shao") return;
        command("slap "+ob->query("id"));
}


int ask_mother ()
{

  if ( this_player()->query("bld/monkey") != 1) {
       command("heng");
       command("say ��ҪϹ�ʣ� \n");
       command("hammer "+this_player()->query("id") );
       return 1;}

  if ( this_player()->query("bld/mother")  == 1) {
       command("say ����ô��ô�������Ǹ��������� \n");
       command("say ��Ҫ�����ң� \n");
       return 1;}
  
  command("say �����豻������ץ���ˣ���Ҫȥ������ \n");
  command("say Ҫ���������ҵ��񸫺ͱ����ƣ�������ô���Ҳ����� \n");
  command("sigh");
  command("say ���ڻ�ɽһλ��ͷ�Ƕ������������¹��� \n");
  command("say �������Ҿȳ����裬��һ��л�㣡 \n");
  command("say ��˵�ˣ���Ҫȥ�������������ˣ����ˡ� \n");
  message_vision("$N����һֻ���������ȥ��\n", this_object());

  this_player()->set("bld/mother",1);
  destruct(this_object());
        
       return 1;
}

void die()
{
  if (environment())
    message("sound", HIW "����" NOR+"����һЦ,����������������\n\n", environment());

  set("eff_kee", 6000);
  set("eff_gin", 6000);
  set("eff_sen", 6000);
  set("kee", 6000);
  set("gin", 6000);
  set("sen", 6000);
  set("force", 20000);
  set("mana", 20000);
}

void unconcious()
{
  die ();
}

