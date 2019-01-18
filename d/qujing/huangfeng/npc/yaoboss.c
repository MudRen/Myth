// created by angell 1/1/2001
// room: /d/qujing/huangfeng/npc/yaoboss.c

inherit F_VENDOR_SALE;

void create()
{
  reload("huangfeng_doctor_huangfeng");
  set_name("���ϰ�", ({"wang laoban", "wang", "laoban"}));
  set("shop_id", ({"laoban", "wang","wang laoban" }));
  set("shop_title", "����");
  set("gender", "����");
  set("combat_exp", 50000);
  set("age", 48);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set_skill("dodge", 30);
  set_skill("parry", 30);
  set("vendor_goods", ([
        "wan": "/d/qujing/tianzhu/obj/wan",
        "fen": "/d/qujing/tianzhu/obj/fen",
        "dan": "/d/qujing/tianzhu/obj/dan",
      ]) );

  setup();
  carry_object("/d/qujing/tianzhu/obj/baipao")->wear();
  carry_object("/d/qujing/tianzhu/obj/simao")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

