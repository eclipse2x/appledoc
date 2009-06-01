//
//  GeneratorBase+GeneralParsingAPI.h
//  appledoc
//
//  Created by Tomaz Kragelj on 28.5.09.
//  Copyright (C) 2009, Tomaz Kragelj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GeneratorBase.h"

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
/** Defines general helper methods private for the @c GeneratorBase and it's subclasses.
*/
@interface GeneratorBase (GeneralParsingAPI)

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Descriptions parsing support
//////////////////////////////////////////////////////////////////////////////////////////

/** Extracts the first brief description paragraph from the given description item.￼

This will return only the first paragraph value from the given item if it exists. It is
useful for generating short descriptions for example.

@param item ￼￼￼￼￼￼The description item which brief description to return.
@return ￼￼￼￼Returns the first brief description paragraph text or @c nil if not found.
@see extractBriefParagraphsFromItem:
@see extractDetailParagraphsFromItem:
@see isDescriptionUsed:
*/
- (NSString*) extractBriefDescriptionFromItem:(id) item;

/** Extracts the brief description paragraphs from the given description item.￼
 
Note that this method assumes there can only be one brief description per a description
item passed to the method. Subclasses can use @c extractParagraphText: to get the actual
text of individual paragraphs.

@param item ￼￼￼￼￼￼The description item which brief description paragraphs to return.
@return ￼￼￼￼Returns the brief item paragraphs or @c nil if brief is empty.
@see extractBriefDescriptionFromItem:
@see extractDetailParagraphsFromItem:
@see extractParagraphText:
@see isDescriptionUsed:
*/
- (NSArray*) extractBriefParagraphsFromItem:(id) item;

/** Extracts the detailed description paragraphs from the given description item.￼
 
Note that this method assumes there can only be one detailed description per a description
item passed to the method. Subclasses can use @c extractParagraphText: to get the actual
text of individual paragraphs.

@param item ￼￼￼￼￼￼The description item which detailed description paragraphs to return.
@return ￼￼￼￼Returns the detailed node paragraphs or @c nil if details are empty.
@see extractBriefDescriptionFromItem:
@see extractBriefParagraphsFromItem:
@see extractParagraphText:
@see isDescriptionUsed:
*/
- (NSArray*) extractDetailParagraphsFromItem:(id) item;

/** Extracts the given paragraph item text.￼

@param item ￼￼￼￼￼￼The paragraph item to extract.
@return ￼￼￼￼Returns the paragraph text or @c nil if not found.
@see extractBriefDescriptionFromItem:
@see extractBriefParagraphsFromItem:
@see extractDetailParagraphsFromItem:
@see isDescriptionUsed:
*/
- (NSString*) extractParagraphText:(id) item;

/** Determines if at least one of the given brief or detailed paragraphs is used or not.￼
 
If at least one paragraph from the given array contains some tekst, the method assumes
it is not empty. Note that all empty paragraphs are already removed from the cleaned 
source in previous steps, but some may still be present...

@param nodes ￼￼￼￼￼￼The array returned from description parsing methods.
@return ￼￼￼￼Returns @c YES if at least one paragraph contains some text.
@see extractBriefDescriptionFromItem:
@see extractBriefParagraphsFromItem:
@see extractDetailParagraphsFromItem:
*/
- (BOOL) isDescriptionUsed:(NSArray*) nodes;

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Miscellaneous parsing helpers
//////////////////////////////////////////////////////////////////////////////////////////

/** Extracts the given sub item from the given item.￼

Note that this method always returns the first subitem if more than one exists.

@param node ￼￼￼￼￼￼The item to extract from.
@param name The name of the subitem to extract.
@return ￼￼￼￼Returns the given subitem or @c nil if doesn't exist.
@warning This method is here because other methods from the category need it, the method
	should not be used by the subclasses and should be regarded as internal!
*/
- (id) extractSubitemFromItem:(id) item
					 withName:(NSString*) name;

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Helper generation methods
//////////////////////////////////////////////////////////////////////////////////////////

/** Appends the given string to the end of the given data, followed by a new line.￼

@param string ￼￼￼￼￼￼The string to append before the new line.
@param data ￼￼￼￼￼￼The data to append to.
@exception ￼￼￼￼￼NSException Thrown if appending fails.
@see appendString:toData:
*/
- (void) appendLine:(NSString*) string toData:(NSMutableData*) data;

/** Appends the given string to the end of the given data.￼

@param string ￼￼￼￼￼￼The string to append.
@param data ￼￼￼￼￼￼The data to append to.
@exception ￼￼￼￼￼NSException Thrown if appending fails.
@see appendLine:toData:
*/
- (void) appendString:(NSString*) string toData:(NSMutableData*) data;

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Properties
//////////////////////////////////////////////////////////////////////////////////////////

/** Returns current output title. */
@property(readonly) NSString* title;

/** Returns current object name. */
@property(readonly) NSString* objectName;

/** Returns current object kind. */
@property(readonly) NSString* objectKind;

/** Returns the names of the class, the current object belongs to.
 
At the moment this is only applicable for categories. */
@property(readonly) NSString* objectClass;

/** Returns current object cleaned XML document. */
@property(readonly) NSXMLDocument* objectMarkup;

/** Returns current object relative directory within the generated output.

This is only the directory and nothing else, in contrary to @c objectRelativePath()
which also returns the file name. */
@property(readonly) NSString* objectRelativeDir;

/** Returns current object relative path within the generated output.
 
This returns the directory and the object name without the extension (the extension should
be specified by each concrete @c GeneratorBase class). See also @c objectRelativeDir(). */
@property(readonly) NSString* objectRelativePath;

@end