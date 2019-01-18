inherit F_CLEAN_UP;

#include <ansi.h>
#include <obstacle.h>
#include "/d/quest/kaifeng/colors.h"

int telling (object me, object who, int short);

string name;

void show_clouds(object me)
{
    mapping colors;
    string *key, msg;
    int i, j;
    if(!me) return;
    
    colors=me->query("quest/colors");
    if(!colors) return;
    i=sizeof(colors);
    if(i<1) return;
    
    key=keys(colors);
    
    if(i==1) {
	msg="������һС��"+key[0]
	    +"ɫ������$N���������\n";
    } else {
	j=i;
	msg="$N����������Ʈ����һС��";
	while(j--) {
	    msg+=key[j];
	}
	if(i==2)
	    msg+="��ɫ���ơ�\n";
	else 
	    msg+=chinese_number(i)+"�����ơ�\n";
    }
    
    if(random(10)==0)
	message_vision(msg,me);
    else {
	msg=replace_string(msg,"$N","��");
	tell_object(me,msg);
    }
}

int main(object me, string arg)
{
        object ob;
	int short;

	short=1;
        if( !arg || arg=="-all") {
                ob = me;
                name = "��";
		if(arg=="-all") short=0;
        } else if (wizardp (me)) {
                ob = find_player(arg);
                if(!ob) ob = find_living(arg);
        
                if(!ob) ob = LOGIN_D->find_body(arg);

                if(!ob || !me->visible(ob)) return notify_fail("û������ˡ�\n");
                name = ob->query("name");
		short=0;
        } else return 0;

        telling(me, ob, short);
	
	if(ob==me) 
	    call_out("show_clouds",1,me);

        return 1;
}

int help()
{
        write(@TEXT
ָ���ʽ��quests <ĳ��>
          quests
	  quests -all

��ʾĳ�˽��յ����ϡ� 

�����help jiemi
TEXT
        );
        return 1;
}

int telling (object me, object who, int short)
{
  mapping mapp;
  if (who->query("quest") == 0)
  {
    write (name+"û�н��κ��ԡ�\n");
    return 1;
  }

  write (name+"�Ѿ�����"+to_chinese(who->query("quest/number"))+"���ԡ�\n");
  
  if(!short) {

  write ("    ʳ�"+"����"+to_chinese(who->query("quest/food/times"))+"�Σ�"+
         "���"+to_chinese(who->query("quest/food/reward"))+"��Ʒ�¡�\n");
  write ("    ���"+"����"+to_chinese(who->query("quest/give/times"))+"�Σ�"+
         "���"+to_chinese(who->query("quest/give/reward"))+"��Ʒ�¡�\n");
  write ("    ���ͣ�"+"����"+to_chinese(who->query("quest/ask/times"))+"�Σ�"+
         "���"+to_chinese(who->query("quest/ask/reward"))+"��Ʒ�¡�\n");
  write ("    ������"+"����"+to_chinese(who->query("quest/kill/times"))+"�Σ�"+
         "���"+to_chinese(who->query("quest/kill/reward"))+"��Ʒ�¡�\n");
  write ("    ������"+"����"+to_chinese(who->query("quest/weapon/times"))+"�Σ�"+
         "���"+to_chinese(who->query("quest/weapon/reward"))+"��Ʒ�¡�\n");
  write ("    ���ף�"+"����"+to_chinese(who->query("quest/armor/times"))+"�Σ�"+
         "���"+to_chinese(who->query("quest/armor/reward"))+"��Ʒ�¡�\n");
  write ("    ļ�裺"+"����"+to_chinese(who->query("quest/cloth/times"))+"�Σ�"+
         "���"+to_chinese(who->query("quest/cloth/reward"))+"��Ʒ�¡�\n");
/*
  write ("    ���Σ�"+"����"+to_chinese(who->query("quest/wearing/times"))+"�Σ�"+
         "���"+to_chinese(who->query("quest/wearing/reward"))+"��Ʒ�¡�\n");
  write ("    ��ʲ��"+"����"+to_chinese(who->query("quest/furniture/times"))+"�Σ�"+
         "���"+to_chinese(who->query("quest/furniture/reward"))+"��Ʒ�¡�\n");
*/
  write ("\n");
  }

  if(!short) {
  write (name+"����ã�\n");
  write ("    Ǳ�ܣ�"+to_chinese(who->query("quest/gain/potential"))+"�㡣\n");
  write ("    ���У�"+COMBAT_D->chinese_daoxing(who->query("quest/gain/daoxing"))+"���С�\n");
  write ("    ���ܣ�\n");
  mapp = who->query("quest/gain/skills");
  if (mapp)
  {
    string *my_keys = keys (mapp);
    int i = sizeof (my_keys);

    while (i--)
    {
       write ("      "+to_chinese(my_keys[i])+to_chinese(mapp[my_keys[i]])
              +"�㡣\n");
    }
  }
  write ("    ���ԣ���ʱ���ƣ���\n");
  mapp = who->query("quest/gain/apply");
  if (mapp)
  {
    string *my_keys = keys (mapp);
    int i = sizeof (my_keys);

    while (i--)
    {
       write ("      "+to_chinese(my_keys[i])+to_chinese(mapp[my_keys[i]])
              +"�㡣\n");
    }
  }
  write ("    ���ӣ�"+to_chinese(who->query("quest/gain/silver"))+"����\n");
  write ("\n");
  }

  write (name+"�ո���ɵ����ǣ�\n");
  if (who->query("quest/reason"))
  {
    write ("  ��"+who->query("quest/reason")+"������");
    if (who->query("quest/reward")) {
      if (wizardp(me)) 
        write ("  ������"+to_chinese(who->query("quest/reward"))+"�㽱����\n");
      else  
        write ("  �����н�����\n");
    }  
    else
      write ("\n");
  }    
  write ("\n");

  write (name+"�������¼������ڽ���ԣ�\n");
  if (mapp = who->query("quest/pending/food"))
  {
    write ("  ʳ�"+mapp["name"]);
    if (wizardp(me))
      write (" �ο�ϵ����"+mapp["index"]+"/"+mapp["daoxing"]+"��\n");
    else 
      write ("\n");
  }
  if (mapp = who->query("quest/pending/give"))
  {
    write ("  ���"+mapp["name"] + " " + mapp["objectname"]);
    if (wizardp(me))
      write (" �ο�ϵ����"+mapp["index"]+"/"+mapp["daoxing"]+"��\n");
    else 
      write ("\n");
  }
  if (mapp = who->query("quest/pending/ask"))
  {
    write ("  ���ͣ�"+mapp["name"]);
    if (wizardp(me))
      write (" �ο�ϵ����"+mapp["index"]+"/"+mapp["daoxing"]+"��\n");
    else 
      write ("\n");
  }
  if (mapp = who->query("quest/pending/kill"))
  {
    write ("  ������"+mapp["name"]);
    if (wizardp(me))
      write (" �ο�ϵ����"+mapp["index"]+"/"+mapp["daoxing"]+"��\n");
    else 
      write ("\n");
  }
  if (mapp = who->query("quest/pending/weapon"))
  {
    write ("  ������"+mapp["name"]);
    if (wizardp(me))
      write (" �ο�ϵ����"+mapp["index"]+"/"+mapp["daoxing"]+"��\n");
    else 
      write ("\n");
  }
  if (mapp = who->query("quest/pending/armor"))
  {
    write ("  ���ף�"+mapp["name"]);
    if (wizardp(me))
      write (" �ο�ϵ����"+mapp["index"]+"/"+mapp["daoxing"]+"��\n");
    else 
      write ("\n");
  }
  if (mapp = who->query("quest/pending/cloth"))
  {
    write ("  ļ�裺"+mapp["name"]);
    if (wizardp(me))
      write (" �ο�ϵ����"+mapp["index"]+"/"+mapp["daoxing"]+"��\n");
    else 
      write ("\n");
  }
/*
  if (mapp = who->query("quest/pending/wearing"))
  {
    write ("  ���Σ�"+mapp["name"]);
    if (wizardp(me))
      write (" �ο�ϵ����"+mapp["index"]+"/"+mapp["daoxing"]+"��\n");
    else 
      write ("\n");
  }
  if (mapp = who->query("quest/pending/furniture"))
  {
    write ("  ��ʲ��"+mapp["name"]);
    if (wizardp(me))
      write (" �ο�ϵ����"+mapp["index"]+"/"+mapp["daoxing"]+"��\n");
    else 
      write ("\n");
  }
*/
  write ("\n");

  if (!wizardp(me))
    return 1;
    
  write (name+"�����ݴ�ʹ��ͳ�ƣ�\n");
  if (mapp = who->query("quest/cache/food"))
  {
    write ("  ʳ�"+to_chinese(sizeof(mapp))+"��\n");
  }
  if (mapp = who->query("quest/cache/give"))
  {
    write ("  ���"+to_chinese(sizeof(mapp))+"��\n");
  }
  if (mapp = who->query("quest/cache/ask"))
  {
    write ("  ���ͣ�"+to_chinese(sizeof(mapp))+"��\n");
  }
  if (mapp = who->query("quest/cache/kill"))
  {
    write ("  ������"+to_chinese(sizeof(mapp))+"��\n");
  }
  if (mapp = who->query("quest/cache/weapon"))
  {
    write ("  ������"+to_chinese(sizeof(mapp))+"��\n");
  }
  if (mapp = who->query("quest/cache/armor"))
  {
    write ("  ���ף�"+to_chinese(sizeof(mapp))+"��\n");
  }
  if (mapp = who->query("quest/cache/cloth"))
  {
    write ("  ļ�裺"+to_chinese(sizeof(mapp))+"��\n");
  }
/*
  if (mapp = who->query("quest/cache/wearing"))
  {
    write ("  ���Σ�"+to_chinese(sizeof(mapp))+"��\n");
  }
  if (mapp = who->query("quest/cache/furniture"))
  {
    write ("  ��ʲ��"+to_chinese(sizeof(mapp))+"��\n");
  }
*/
  write ("\n");
  return 1;
}


