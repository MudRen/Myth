//
//written by stey 2002/12/10
#include <ansi.h>

inherit ITEM;
#define base      "/daemon/hellfire/base/"


mapping files_type=([
     "����"        :    "/daemon/hellfire/swordman/",
     "������"        :   "/daemon/hellfire/swordman/",
     "ħ��ʦ"        :   "/daemon/hellfire/magicman/",
     "�ս���"        :   "/daemon/hellfire/destoryer/",
     "������"        :   "/daemon/hellfire/spirit/",
     "���ڵ���ʹ��"   :  "/daemon/hellfire/darkness/",
     "Ұ����"        :   "/daemon/hellfire/barbarian/",

]);

void create()
{
        seteuid(0);
        set_name(HIC"ħ����"NOR,({ "magic book", "magic_book",}) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("value", 2000000);

                set("unit","��");
                set("color","b");  //HIB
                set("no_put",1);
                set("no_sell",1);
                set("no_get",1);
                set("no_give",1);
                set("no_drop",1);
                set("long",HIB"�����񻰵�����ħ�������顣\n"NOR);
        }
        setup();
}

void init ()
{
        object ob=this_object();
  if(environment(ob)->query("id")!=ob->query("owner_id"))
       {
        destruct(ob);
     return;
        }
  add_action ("do_check","magiclist");
  add_action ("do_cast", "magicast");
  add_action ("do_magichelp","magichelp");
}


int do_check(string arg)
{
       object me;
       mixed* basefile, magicfile;
       string helltype,str,strb,strc,strd;
       int i,j,k;

       me=this_player();
       if(me->is_fight() || me->is_busy())
               return notify_fail("������û�գ�\n");

       if(!(helltype=me->query("hell_type")))
               return notify_fail("������ͨũ��ɶ�����ᣡ\n");

       basefile = get_dir( base+"*.c", -1 );

       if( sizeof(basefile)>0 )
       {

          str ="������Ļ���ħ����\n";
          str +="��������������������������������������������������������\n";
          for(i=0;i<sizeof(basefile);i++)
          {
                strb=HIR+"����"+NOR;
                //�����Ժ���
                if(!(strc = (base+basefile[i][0])->get_name()))
                       strc = basefile[i][0];

                 strc = replace_string( strc, ".c", "");
                 strd= replace_string( basefile[i][0], ".c", "");
                 k=i+1;
                 str = sprintf("%s%s(%s)%18s%2s",
                                   str,
                                   HIC"��"+NOR+strc+HIC+"��",
                                   strd,
                                   strb,
                                   k%2 ? "": "\n");
          }
          str +="\n";
        }

        if(undefinedp(files_type[helltype]))
         {
                write(str+"\n");
                return 1;
         }

        magicfile = get_dir( files_type[helltype]+"*.c", -1 );


          if( sizeof(magicfile)>0 )
       {
          str +="��������������������������������������������������������\n";
          str +="�������"+helltype+"����ħ����\n";

          for(i=0;i<sizeof(magicfile);i++)
          {
                if((j=me->query("hellfire_magic/"+magicfile[i][0])))
                    strb=HIG+""+j+" ��"+NOR;
                        else strb=HIR+"����";
                if(!(strc = ( files_type[helltype] + magicfile[i][0])->get_name()))
                       strc = magicfile[i][0];

                  strc = replace_string( strc, ".c", "");
                  strd= replace_string( magicfile[i][0], ".c", "");
                 k=i+1;
                 str = sprintf("%s%s(%s)%18s%2s",
                                   str,
                                   HIC"��"+NOR+strc+HIC+"��",
                                   strd,
                                   strb,
                                  k%2 ? "": "\n");
          }
          str +="��������������������������������������������������������\n";
        }

        write(str+"\n");
        return 1;
}

int do_cast(string arg)
{
       object me,ob,target,env;
       mixed* basefile, magicfile;
       string helltype,spells, spl, trg,fangwei;

       int i,j,k;


        me=this_player();
        if(!arg) return notify_fail("��׼����ʲô��\n");
        env=environment(me);
        if((int)me->query_temp("no_cast")==1)
                return notify_fail("�����ڲ�����ħ����\n");

        if( me->is_busy() )
                return notify_fail("( ����һ��������û����ɣ����������ġ�)\n");

        if( !wizardp(me) && env->query("no_magic")&& !env->query("hellfireroom") )
                return notify_fail("���ﲻ׼�����ġ�\n");

        if(!(helltype=me->query("hell_type")) &&  undefinedp(files_type[helltype]))
               return notify_fail("������ͨũ��ɶ�����ᣡ\n");
        if( sscanf(arg, "%s on %s", spl, trg)==2 )
        {
                if( sscanf(trg, "%s for %s", trg,fangwei)!=2 )
                       fangwei=0;
                target = present(trg, env);
//              if( !target ) target = present(trg, me);
                if( !target ) return notify_fail("����û�� " + trg + "��\n");

//              if(!valid_kill(me,target,0)) return 0;

                if( env != environment(target))
                    return notify_fail("����û�� " + trg + "��\n");
                if( userp(me) && userp(target) &&
                    target->query_temp("netdead") )
                   return notify_fail("�Է����ڶ����У����ܶ���ʩ����\n");
        }
         else {
                spl = arg;
                target = 0;
                fangwei=0;
              }

        spl = replace_string( spl, " ", "_");

        if(file_size(base+spl+".c")!=-1)
        {

          (base+spl+".c")->do_cast(me,target,fangwei);
          return 1;
         }
         else
         if( file_size(files_type[helltype]+spl+".c")!=-1)
          {
                (files_type[helltype]+spl+".c")->do_cast(me,target,fangwei);
                return 1;
          }

          return 1;
}


int do_magichelp(string arg)
{
       object me;
       mixed* basefile, magicfile;
       string helltype,spl,str;
       int i,j,k;

       me=this_player();
        if(!arg) return notify_fail("��׼����ʲô��\n");
        if(me->is_fight() || me->is_busy())
               return notify_fail("������û�գ�\n");

        if(!(helltype=me->query("hell_type")) &&  undefinedp(files_type[helltype]))
               return notify_fail("������ͨũ��ɶ�����ᣡ\n");


        spl = replace_string( arg, " ", "_");

        if(file_size(base+spl+".c")!=-1)
        {

          if((str=(base+spl+".c")->get_help()))
          write(str+"\n");


         }
         else
         if( file_size(files_type[helltype]+spl+".c")!=-1)
          {
                if((str=(files_type[helltype]+spl+".c")->get_help()))
                write(str+"\n");
          }
          else write("This magic power no help <or> No this magic!\n");
          return 1;
}



